/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
int relayState = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

String command = "";
// the loop routine runs over and over again forever:
void loop() {
//  if (Serial.available() > 0) {
    while (Serial.available() > 0){
        char serIn = Serial.read();  //read Serial   

        // debug
        // Serial.println(serIn);
        
        if(serIn == '{'){
            command = ""; 
            continue;
        }
        if(serIn == '}'){
          if(command == "ON"){
            analogWrite(A3, 1024);
          }
          if(command == "OFF"){
            analogWrite(A3, 0);
          }
          command = "";
        } else {
          command += serIn;
        }
    }
}

