
  // William Hughes
  // Coach L
  // engineering technology
  // b block 

bool buttonVal = false;

void setup(){
  pinMode(A0,INPUT);
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,INPUT);
  attachInterrupt(digitalPinToInterrupt(13),buttonISR,FALLING);
}

void buttonISR(){
  buttonVal = !buttonVal;
}
  
 void loop(){

  //digitalWrite(12,HIGH);
    
    int photoValue = map(analogRead(A0),25,170,0,255);
    Serial.println(photoValue);
    Serial.print("buttonVal:");
    Serial.println(buttonVal);
    analogWrite(3,photoValue);
    if(buttonVal){
      // button is true
      tone(12, 200);


      
    } else {
      // buyton is false
      noTone(12);
    }
    
    delay(200);
 }


 
