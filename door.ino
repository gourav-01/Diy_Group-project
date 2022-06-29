#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos,s=0; 
 
i=0;

int naba();
String readdata;
void setup() {
  Serial.begin(9600);
  myservo.attach(9); 
  myservo.write(0);
 
}

void loop() {
  
if (Serial.available())
     readdata="";
     while (Serial.available()){ 
    //Check if there is an available byte to read
delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
readdata = c; //build the string- "forward", "reverse", "left" and "right"
  } 
  if (readdata.length() > 0) {

Serial.println(readdata);
if(readdata == "A"&&i==0) 
{
  for(pos=0;pos<=90;pos+=5)
   { myservo.write(pos);
   delay(20);
   }
   i=1;
    readdata="";
}
if(readdata =="B"&&i==1)
{
  for(pos=90;pos>0;pos-=5)
   { myservo.write(pos);
   delay(20);
   }
   i=0;
    
   s=0;
    readdata="";
}

}}
