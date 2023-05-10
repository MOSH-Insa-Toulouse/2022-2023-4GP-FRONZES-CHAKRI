/*
  File : CapteurGraphite.ino
  Description : Allows calibration, control and data acquisition of the sensor
  Authors : Anouk FRONZES, Léo CHAKRI
  Created on : 12.03.2023
*/



/* *** Libraries and constants *** */

// OLED SCREEN
#include <Adafruit_SSD1306.h>
#define PixelsLenghtOLED 128                                              //OLED screen size, in pixels, at its length
#define PixelsWidthOLED 64                                                //OLED screen size, in pixels, at its width
#define ResetPinOLED -1                                                   //reset of OLED shared with the Arduin 
#define I2CAdressOLED 0x3C                                                //address of the OLED display on the I2C bus (usually 0x3C or 0x3D)
#define CharacterSize 0.8   

Adafruit_SSD1306 OLEDScreen(PixelsLenghtOLED, PixelsWidthOLED, &Wire, ResetPinOLED);

// BLUETOOTH
#include <SoftwareSerial.h>
#define rxPin 9                                                          //Pin 11 as RX, connect to TX of HC-05
#define txPin 8                                                          //Pin 10 as RX, connect to TX of HC-05
#define Clock 50                                                          //Clock for sending data via bluetooth

SoftwareSerial mySerial(rxPin ,txPin);                                    //Definition of software serial
unsigned long t=0;

// SENSOR
float SensorResistance = 0.0;
const int flexPin = A1;
const float VCC = 5;                                                      //voltage at Ardunio 5V line
const float R_DIV = 39000.0;                                              //resistor used to create a voltage divider
const float flatResistance = 24500.0;                                     //resistance when flat
const float bendResistance = 65000.0;                                     //resistance at 90 deg



/* *** Sub-programs *** */

// OLED SCREEN
void DisplayOLED (float SensorResistance, float FlexSensorResistance) {   //display data on the OLED screen

  SensorResistance=SensorResistance/1000000;                              //converts value into Mohms
  FlexSensorResistance=FlexSensorResistance/1000000;                      //converts value into Mohms

  //settings
  OLEDScreen.clearDisplay();
  OLEDScreen.setTextSize(CharacterSize);
  OLEDScreen.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
  OLEDScreen.setCursor(0, 0);
  //data desplay
  OLEDScreen.print("RSens: ");
  OLEDScreen.print(SensorResistance);
  OLEDScreen.println(" MOhm");
  OLEDScreen.println("");
  OLEDScreen.print("Rflex: ");
  OLEDScreen.print(FlexSensorResistance);
  OLEDScreen.println(" MOhm");
  OLEDScreen.display();

}



/* *** SETUP *** */

void setup() {

  OLEDScreen.begin(SSD1306_SWITCHCAPVCC, I2CAdressOLED);                  //OLED initialization

  pinMode(flexPin, INPUT);                                                //pin initialization
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);

  Serial.begin(9600);
  mySerial.begin(9600);

}



/* *** LOOP *** */

void loop() {

  int ADCflex = analogRead(flexPin);                                      //reading Arduino's flexpin value (flex sensor)
  float Vflex = ADCflex * VCC / 1023.0;                                   //converts it to voltage
  float Rflex = R_DIV * (VCC / Vflex - 1.0);                              //converts it to sensor resistance

  float sensorValue = analogRead(A0);                                     //reading Arduino's sensorpin value (graphite sensor)
  float SensorResistance = 50500000/sensorValue - 110000;                 //converts it to resistance (parameters depend on the circuit)

  DisplayOLED(SensorResistance,Rflex);                                    //data display on the OLED screen

  Serial.println(SensorResistance);                                       //data display on serial monitor

  if (abs(millis()-t) > Clock){                                
    t=millis();
    byte V = map(sensorValue,0,1023,0,255);                          //converts resistance to byte 
    mySerial.write(V);                                                    //send data to smartphone
  }

  delay(10);

}
