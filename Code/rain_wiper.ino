
#include <Servo.h>

Servo myservo; 

int pos = 0; 
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  delay(3000); 
}



void wipe(int Speed)
{

  if(Speed>400){Speed=5000;}
  if(Speed>350&&Speed<=400){Speed=3000;}
  if(Speed<=350){Speed=500;}
  for (pos = 120; pos >= 0; pos--) {
    myservo.write(pos);            
    delay(3);                    
  }
  for (pos = 0; pos <= 120; pos++) { 
    myservo.write(pos);             
    delay(3);                       
  }
  delay(Speed);
}




void loop() 
{
sensorValue = analogRead(A0);
Serial.println(sensorValue);
if(sensorValue>600){myservo.write(180);delay(1000);}
if(sensorValue<=600){wipe(sensorValue);}
}
