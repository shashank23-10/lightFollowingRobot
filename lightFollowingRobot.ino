#include<Servo.h>
Servo mymotor;

#define motor1a 2 
#define motor1b 3
#define motor2a 4
#define motor2b 5
  
#define ldr1 A5
#define ldr2 A4
#define ldr3 A3

void setup()
{
  Serial.begin(9600);
  
  mymotor.attach(8);
  
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(ldr3, INPUT);
  
  pinMode(motor1a, OUTPUT);
  pinMode(motor1b, OUTPUT);
 
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT);
}

void forward(){
  digitalWrite(motor1a, HIGH);
  digitalWrite(motor1b, LOW);
    
  digitalWrite(motor2a, HIGH);
  digitalWrite(motor2b, LOW);
}
void backward(){
  digitalWrite(motor1a, LOW);
  digitalWrite(motor1b, HIGH);
    
  digitalWrite(motor2a, LOW);
  digitalWrite(motor2b, HIGH);
}
void left(){
  digitalWrite(motor1a, HIGH);
  digitalWrite(motor1b, LOW);
    
  digitalWrite(motor2a, LOW);
  digitalWrite(motor2b, HIGH);
}
void right(){
  digitalWrite(motor1a, LOW);
  digitalWrite(motor1b, HIGH);
    
  digitalWrite(motor2a, HIGH);
  digitalWrite(motor2b, LOW);
}
void stop(){
  digitalWrite(motor1a, LOW);
  digitalWrite(motor1b, LOW);
    
  digitalWrite(motor2a, LOW);
  digitalWrite(motor2b, LOW);
}
void loop()
{
  int ldr1_value=analogRead(ldr1);
  int ldr2_value=analogRead(ldr2);
  int ldr3_value=analogRead(ldr3);

  
  int totalLight = ldr1_value + ldr2_value + ldr3_value;
  
  Serial.print("Total light intensity=");
  Serial.println(totalLight);
  
  if(totalLight>450)
  {
    mymotor.write(0);
    forward();
  }
  else if(totalLight>300){
    backward();
    delay(1000);
    mymotor.write(120);
    delay(1000);
    mymotor.write(30);
    delay(1000);
    left();
    delay(1000);
    right();
  }
  else{
    stop();
  }
}

