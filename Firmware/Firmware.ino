// Include Libraries
#include "Arduino.h"
#include "BTHC05.h"
#include "DCMDriverL298.h"


// Pin Definitions
#define BTHC05_PIN_RXD	10
#define BTHC05_PIN_TXD	11
#define DCMOTORDRIVERL298_PIN_ENA	5
#define DCMOTORDRIVERL298_PIN_INT1	2
#define DCMOTORDRIVERL298_PIN_INT2	3
#define DCMOTORDRIVERL298_PIN_ENB	6
#define DCMOTORDRIVERL298_PIN_INT3	4
#define DCMOTORDRIVERL298_PIN_INT4	7



// Global variables and defines

// object initialization
BTHC05 bthc05(BTHC05_PIN_RXD,BTHC05_PIN_TXD);
DCMDriverL298 dcMotorDriverL298(DCMOTORDRIVERL298_PIN_ENA,DCMOTORDRIVERL298_PIN_INT1,DCMOTORDRIVERL298_PIN_INT2,DCMOTORDRIVERL298_PIN_ENB,DCMOTORDRIVERL298_PIN_INT3,DCMOTORDRIVERL298_PIN_INT4);



// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    bthc05.begin(9600);
    
    bthc05.println("Bluetooth On....");
    //menuOption = menu();
    pinMode(13, OUTPUT);        //Sets digital pin 13 as output pin
    
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    //if(menuOption == '1') {
    // BTHC05_SoftwareSerial - Test Code
    String bthc05Str = "1";
    //Receive String from bluetooth device
    if (bthc05.available())
    {
        //Read a complete line from bluetooth terminal
        bthc05Str = bthc05.readStringUntil('\n');
        // Print raw data to serial monitor
        Serial.print("BT Raw Data: ");
        Serial.println(bthc05Str);
    }
    //Send sensor data to Bluetooth device  
   // bthc05.println("PUT YOUR SENSOR DATA HERE");
    //}
    /*if(bthc05Str == "g") {
    // DCMDriverL298 - Test Code
    //Start both motors. note that rotation direction is determined by the motors connection to the driver.
    //You can change the speed by setting a value between 0-255, and set the direction by changing between 1 and 0.
    Serial.print("Main Gate is open");
    dcMotorDriverL298.setMotorB(255,1);
    //dcMotorDriverL298.setMotorB(200,0);
    delay(1000);
    //Stop both motors
    dcMotorDriverL298.stopMotors();
    //delay(1000);
    } */

    if(bthc05Str == "g") {
    // DCMDriverL298 - Test Code
    //Start both motors. note that rotation direction is determined by the motors connection to the driver.
    //You can change the speed by setting a value between 0-255, and set the direction by changing between 1 and 0.
    Serial.print("clockible is a open");
    dcMotorDriverL298.setMotorA(150,1);
    dcMotorDriverL298.setMotorB(0,0);
    delay(800);
    //Stop both motors
    dcMotorDriverL298.stopMotors();
    //delay(2000);

  digitalWrite(13, HIGH);   //If value is 0 then LED turns OFF
    }

    else if(bthc05Str == "cg") {
    // DCMDriverL298 - Test Code
    //Start both motors. note that rotation direction is determined by the motors connection to the driver.
    //You can change the speed by setting a value between 0-255, and set the direction by changing between 1 and 0.
    Serial.print("anticlockible is a open");
    dcMotorDriverL298.setMotorA(150,0);
    dcMotorDriverL298.setMotorB(0,1);
    delay(600);
    //Stop both motors
    dcMotorDriverL298.stopMotors();
    //delay(2000);

    digitalWrite(13, LOW);  //If value is 1 then LED turns ON
    }

    else if(bthc05Str == "f") {
    // DCMDriverL298 - Test Code
    //Start both motors. note that rotation direction is determined by the motors connection to the driver.
    //You can change the speed by setting a value between 0-255, and set the direction by changing between 1 and 0.
    Serial.print("clockible is b open");
    dcMotorDriverL298.setMotorB(200,1);
    dcMotorDriverL298.setMotorA(0,0);
    delay(2000);
    //Stop both motors
    dcMotorDriverL298.stopMotors();
    //delay(2000);

    }

    else if(bthc05Str == "cf") {
    // DCMDriverL298 - Test Code
    //Start both motors. note that rotation direction is determined by the motors connection to the driver.
    //You can change the speed by setting a value between 0-255, and set the direction by changing between 1 and 0.
    Serial.print("anti clockible is b open");
    dcMotorDriverL298.setMotorB(200,0);
    dcMotorDriverL298.setMotorA(0,1);
    delay(2000);
    //Stop both motors
    dcMotorDriverL298.stopMotors();
    //delay(2000);

    }

  



