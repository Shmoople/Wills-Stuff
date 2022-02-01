/************************************
|   Author: William Hughes          |
|   Teacher: Coach L                |
|   Class: Electrical Engineering   |
|   Block: B                        |
|   Program: Tutorial 7 and 8       |
************************************/

volatile bool buttonValue = false; // boolean variable used to hold the button state

void buttonISR() // interrupt service routine
{
    buttonValue = !buttonValue; // flip buttonVal's state
} // end of interrupt service routine


void setup() // built-in setup function
{
    /* SETUP INPUT AND OUTPUT PINS */
    pinMode(A0,INPUT); // A0 is the photoresistor read pin
    pinMode(13,INPUT); // D13 is the 'momentary contact switch' pin
    pinMode(3,OUTPUT); // D3 is the led pin 
    pinMode(12,OUTPUT); // D12 is the piezo pin
    

    /* SETUP ISR PIN */
    attachInterrupt(digitalPinToInterrupt(13),buttonISR,FALLING); // call 'buttonISR()' when D13 is low

    /* INITIALIZE SERIAL MONITOR */
    Serial.begin(9600); // baud rate is 9600
} // end of setup


void loop() // built-in loop function
{
    /* READ PHOTORESISTOR VALUE */
    int photoValue = map(analogRead(A0),25,170,0,255); // map the raw analog range to an easier to see brightness range
    
    Serial.print("Time: "); // assertment for debugging 
    Serial.println(millis()/100); // display the amount of time since the program started running (in seconds)
    Serial.print("photoValue: "); // assertment for debugging
    Serial.println(photoValue); // display the photoresistor analog input
    Serial.print("buttonValue: "); // assertment for debugging
    Serial.println(buttonValue); // display the button sate digital input

    /* UPDATE LED OUTPUT */
    analogWrite(3,photoValue); // set the brightness of the led to the photoValue
    
    /* CHECK FOR BUTTON STATE OUTPUT */
    if(buttonValue) // if the button is toggled on
    {
        tone(12, 200); // play the tune
    }
    else // if the button is toggled off 
    {
        noTone(12); // turn off all music
    } // end of if-else statement
} // end of loop
