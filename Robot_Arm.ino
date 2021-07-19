 #include <Servo.h>

#define servo1 8
#define servo2 6

Servo  mservo1, mservo2;

int pos = 0;
char Incoming_value = 0;
char usechar = "0";

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  

  mservo1.attach(servo1); // 0-180
  mservo2.attach(servo2); // 0-35

  //default servo position

  mservo1.write(0); //left-right
  mservo2.write(0); //clamp
}


int srv1 = 0;

int srv2 = 0;

void loop() 
{

  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();
    //Serial.println(Incoming_value);
    usechar = Incoming_value;
  }

  if(usechar=='0')
  {
    
  }
  

  if(usechar=='C')
  {
    if(srv1<180)
    {
      srv1++;
      mservo1.write(srv1);
      
      delay(10);
     }
  }

  if(usechar=='D')
  {
    if(srv1>0)
    {
      srv1--;
      mservo1.write(srv1);
      
      delay(10);
     }
  }


   //-----

   if(usechar=='F')
  {
    if(srv2<35)
    {
      srv2++;
      mservo2.write(srv2);
      
      delay(10);
     }
   }
   
   if(usechar=='I')
   {
    if(srv2>0)
    {
      srv2--;
      mservo2.write(srv2);
      
      delay(10);
     }
   }

   
      
}
