/*
NAME OF THE PROJECT : SIGN LANGUAGE TRANSLATOR
MADE BY - MANMOHAN GUPTA

THIS PROJECT READS SENSOR VALUE AND TRY TO UNDERSTAND SYMBOLS GENERATED FROM AMERICAN SIGN LANGUAGE (ASL) CHART
AND DISPLAY ON A SMARTPHONE.
-------PIN CONFIGURATION----------------
A0-A4 : FLEX SENSOR
D4&D5 : FOR BLUETOOTH RX AND TX
A5&A6 : XPIN AND YPIN FOR ACCELROMETER
*/

#include <SoftwareSerial.h>

SoftwareSerial mySerial(5,4);

// Change these constants according to your project's design
const float VCC = 5;      // voltage at Ardunio 5V line
const float R_DIV = 47000.0;  // resistor used to create a voltage divider
const float flatResistance = 450; // resistance when flat
const float bendResistance = 650;  // resistance at 90 deg

float newAngle, previousAngle1 ,previousAngle2 , previousAngle3 , previousAngle4 , previousAngle5;


char temp = '0';
int flag = 0; int LED = 8;
//variable initializtion
int xpin = A5;
int xadc = 0;
int sxadc = 0;
int xmax = 0;
int xmin = 1023;

int ypin = A6;
int yadc = 0;
int syadc = 0;
int ymax = 0;
int ymin = 1023;

int FLEX_PIN1 = A0; 
int flexADC1 = 0; 
int sensorMin1 = 1023; 
int sensorMax1 = 0;

int FLEX_PIN2 = A1; 
int flexADC2 = 0; 
int sensorMin2 = 1023; 
int sensorMax2 = 0;

int FLEX_PIN3 = A2; 
int flexADC3 = 0; 
int sensorMin3 = 1023; 
int sensorMax3 = 0;

int FLEX_PIN4 = A3; 
int flexADC4 = 0; 
int sensorMin4 = 1023; 
int sensorMax4 = 0;

int FLEX_PIN5 = A4; 
int flexADC5 = 0; 
int sensorMin5 = 1023; 
int sensorMax5 = 0;


void setup() 
{
  mySerial.begin(9600);
  Serial.begin(9600);


 pinMode(LED, OUTPUT); 
while (!Serial) 
{
; // wait for serial port to connect. Needed for native USB port only
}

// callibrating the sensors for adaptivity with different bends
while(millis()<15000)
{
  pinMode(FLEX_PIN1, INPUT);
  pinMode(FLEX_PIN2, INPUT);
  pinMode(FLEX_PIN3, INPUT);
  pinMode(FLEX_PIN4, INPUT);
  pinMode(FLEX_PIN5, INPUT);
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
//if(digitalRead(7)==HIGH)
//{
//  Serial.println("inside hight");
//float flexADC1 = analogRead(FLEX_PIN1);
//float flexADC2 = analogRead(FLEX_PIN2);
//float flexADC3 = analogRead(FLEX_PIN3);
//float flexADC4 = analogRead(FLEX_PIN4);
//float flexADC5 = analogRead(FLEX_PIN5);
//
//if(flexADC1<sensorMin1)
//{
//sensorMin1=flexADC1;
//}
//if(flexADC1>sensorMax1)
//{
//sensorMax1=flexADC1;
//}
//
//if(flexADC2<sensorMin2)
//{
//sensorMin2=flexADC2;
//}
//if(flexADC2>sensorMax2)
//{
//sensorMax2=flexADC2;
//}
//
//if(flexADC3<sensorMin3)
//{
//sensorMin3=flexADC3;
//}
//if(flexADC3>sensorMax3)
//{
//sensorMax4=flexADC4;
//}
//
//if(flexADC5<sensorMin5)
//{
//sensorMin5=flexADC5;
//}
//if(flexADC5>sensorMax5)
//{
//sensorMax5=flexADC5;
//}
//
//if(flexADC4<sensorMin4)
//{
//sensorMin4=flexADC4;
//}
//if(flexADC4>sensorMax4)
//{
//sensorMax4=flexADC4;
//}
//}
}
}

void printfun(char cp){
  if(cp!=temp){
  mySerial.print(cp);
 //mySerial.print("hi");

temp=cp;
//temp=cp;
  }
}

void printfun1(float ang1 , float ang2 ,float ang3,float ang4,float ang5  ) //to avoid printing repeating symbols
{
//if(cp!=temp)
//{
  Serial.print("#1 : ");
Serial.println(ang1);
  Serial.print("#2 : ");
Serial.println(ang2);
  Serial.print("#3 : ");
Serial.println(ang3);
  Serial.print("#4 : ");
Serial.println(ang4);
  Serial.print("#5 : ");
Serial.println(ang5);


//mySerial.print("hi");

//temp=cp;
//}
}

void loop() 
{
//   if (mySerial.available()) 
//   flag = mySerial.read(); 
// if (flag) 
// { 
//   digitalWrite(LED, HIGH); 
//  // Serial.println(flag); 
// } 
// else if (flag == 0) 
// { 
//   digitalWrite(LED, HIGH); 
//   Serial.println("LED Off"); 
// }
//
//  analogReference(EXTERNAL); //connect AREF to 3.3V 
// reading sensor value
float flexADC1 = analogRead(FLEX_PIN1);
float flexADC2 = analogRead(FLEX_PIN2);
float flexADC3 = analogRead(FLEX_PIN3);
float flexADC4 = analogRead(FLEX_PIN4);
float flexADC5 = analogRead(FLEX_PIN5);

Serial.print("felx  ");
Serial.println( flexADC3);
     float angle1 = map(flexADC1, flatResistance, bendResistance, 0, 90);
    angle1 = constrain(angle1, 0, 90); // optional
//    if (angle1 != previousAngle1) {
//    Serial.print("Bend1: ");
//    Serial.print(angle1);
//    Serial.println(" degrees");
//    previousAngle1 = angle1;
//  }
////Serial.println(flexADC2);
       float angle2 = map(flexADC2, flatResistance,550, 0, 90);
    angle2 = constrain(angle2, 0, 90); // optional
//    if (angle2 != previousAngle2) {
//    Serial.print("Bend2: ");
//    Serial.print(angle2);
//    Serial.println(" degrees");
//    previousAngle2 = angle2;
//  }

         float angle3 = map(flexADC3, 370,424, 0, 90);
    angle3 = constrain(angle3, 0, 90); // optional
//    if (angle3 != previousAngle3) {
//    Serial.print("Bend3: ");
//    Serial.print(angle3);
//    Serial.println(" degrees");
//    previousAngle3 = angle3;
//  }

//
         float angle4 = map(flexADC4, flatResistance,550, 0, 90);
    angle4 = constrain(angle4, 0, 90); // optional
//    if (angle4 != previousAngle4) {
//    Serial.print("Bend4: ");
//    Serial.print(angle4);
//    Serial.println(" degrees");
//    previousAngle4 = angle4;
//  }
//Serial.println(flexADC5);

           float angle5 = map(flexADC5, flatResistance,550, 0, 90);
    angle5 = constrain(angle5, 0, 90); // optional
//    if (angle5 != previousAngle5) {
//    Serial.print("Bend5: ");
//    Serial.print(angle5);
//    Serial.println(" degrees");
//    previousAngle5 = angle5;
//  }


printfun1(angle1 ,angle2 , angle3 ,angle4 ,angle5 );


//flexADC1 = constrain(flexADC1,sensorMin1, sensorMax1);
//flexADC2 = constrain(flexADC2,sensorMin2, sensorMax2);
//flexADC3 = constrain(flexADC3,sensorMin3, sensorMax3);
//flexADC4 = constrain(flexADC4,sensorMin4, sensorMax4);
//flexADC5 = constrain(flexADC5,sensorMin5, sensorMax5);
//printfun(flexADC1,flexADC2);
//
////printfun('A' , flexADC1, flexADC2 , flexADC3,flexADC4,flexADC5);
//
//float angle1= map(flexADC1, sensorMin1, sensorMax1, 0, 90);
//
//float angle2= map(flexADC2, sensorMin2, sensorMax2, 0, 90);
////printfun(angle1,angle2);
//float angle3= map(flexADC3, sensorMin3, sensorMax3, 0, 90);//printfun(angle3);
//
//float angle4= map(flexADC4, sensorMin4, sensorMax4, 0, 90);//printfun(angle4);
//float angle5= map(flexADC5, sensorMin5, sensorMax5, 0, 90); //printfun(angle5);
////printfun(angle1,angle2);
//
xadc = analogRead(xpin);
delay(1);
yadc = analogRead(ypin);         

Serial.print("x-axis : "); 
Serial.println(xadc);
Serial.print("y-axis : "); 
Serial.println(yadc);


//Serial.print("s-x-axis : "); 
//Serial.println(sxadc);
//Serial.print("s-y-axis : "); 
//Serial.println(syadc);
if(((angle1>=70)&&(angle1<=90))&&((angle2>=70)&&(angle2<=90))&&((angle3>=70)&&(angle3<=90))&&((angle4>=70)&&(angle4<=90))&&((angle5>=0)&&(angle5<=10))){
Serial.println("A");
//mySerial.println('A');
}
if(((angle1>=0)&&(angle1<=20))&&((angle2>=0)&&(angle2<=10))&&((angle3>=0)&&(angle3<=12))&&((angle4>=0)&&(angle4<=10))&&((angle5>=65)&&(angle5<=90))){
Serial.println("B");
//mySerial.println('B');
printfun('B');
}
if(((angle1>=20)&&(angle1<=65))&&((angle2>=10)&&(angle2<=65))&&((angle3>=0)&&(angle3<=35))&&((angle4>=0)&&(angle4<=30))&&((angle5>=0)&&(angle5<=20))){
  Serial.println("C");
 // mySerial.println('C');
  printfun('C');
  //}
}

if(((angle1>=50)&&(angle1<=90))&&((angle2>=45)&&(angle2<=90))&&((angle3>=35)&&(angle3<=90))&&((angle4>=0)&&(angle4<=10))&&((angle5>=45)&&(angle5<=90))){
printfun('D');
 Serial.println("D");
}
if(((angle1>=60)&&(angle1<=90))&&((angle2>=68)&&(angle2<=90))&&((angle3>=60)&&(angle3<=90))&&((angle4>=54)&&(angle4<=90))&&((angle5>=58)&&(angle5<=90))){
printfun('E');
 Serial.println("E");
}
if(((angle1>=0)&&(angle1<=30))&&((angle2>=0)&&(angle2<=30))&&((angle3>=0)&&(angle3<=30))&&((angle5>=45)&&(angle5<=95))&&((angle4>=20)&&(angle4<=65))){
printfun('F');
 Serial.println("F");
}
if(((angle1>=55)&&(angle1<=90))&&((angle2>=55)&&(angle2<=90))&&((angle3>=20)&&(angle3<=90))&&((angle4>=50)&&(angle4<=90))&&((angle5>=50)&&(angle5<=90))){
//printfun('G');
 //Serial.println("G");
}
if(((angle1>=50)&&(angle1<=90))&&((angle2>=55)&&(angle2<=90))&&((angle3>=0)&&(angle3<=10))&&((angle4>=0)&&(angle4<=10))&&((angle5>=20)&&(angle5<=75))){
printfun('H');
 Serial.println("H");
}
if(((angle1>=0)&&(angle1<=25))&&((angle2>=50)&&(angle2<=90))&&((angle3>=40)&&(angle3<=90))&&((angle4>=50)&&(angle4<=90))&&((angle5>=50)&&(angle5<=90))){
printfun('I');
Serial.println("I");
}
//if(((angle1>=0)&&(angle1<=10))&&((angle2>=50)&&(angle2<=70))&&((angle3>=50)&&(angle3<=70))&&((angle4>=50)&&(angle4<=70))&&((angle5>=50)&&(angle5<=85))&&(!((xadc>=410)&&(xadc<=420))&&((yadc>=355)&&(yadc<=370))))
//printfun('J');
//if(((angle1>=60)&&(angle1<=75))&&((angle2>=60)&&(angle2<=85))&&((angle3>=0)&&(angle3<=10))&&((angle4>=0)&&(angle4<=15))&&((angle5>=30)&&(angle5<=55))&&(((xadc>=404)&&(xadc<=415))&&((yadc>=368)&&(yadc<=380))))
if(((angle1>=60)&&(angle1<=90))&&((angle2>=60)&&(angle2<=90))&&((angle3>=0)&&(angle3<=20))&&((angle4>=0)&&(angle4<=20))&&((angle5>=0)&&(angle5<=20))){
 printfun('K');

Serial.println('K');
}
//if(((angle1>=75)&&(angle1<=90))&&((angle2>=75)&&(angle2<=90))&&((angle3>=70)&&(angle3<=90))&&((angle4>=0)&&(angle4<=15))&&((angle5>=0)&&(angle5<=30))&&(((xadc>=390)&&(xadc<=405))&&((yadc>=360)&&(yadc<=380)))&&!((xadc>=270)&&(xadc<=300))&&((yadc>=360)&&(yadc<=390)))
if(((angle1>=55)&&(angle1<=90))&&((angle2>=55)&&(angle2<=90))&&((angle3>=55)&&(angle3<=90))&&((angle4>=0)&&(angle4<=25))&&((angle5>=0)&&(angle5<=25))){

 printfun('L'); 

Serial.println('L');
}

//if(((angle1>=40)&&(angle1<=61))&&((angle2>=72)&&(angle2<=84))&&((angle3>=45)&&(angle3<=65))&&((angle4>=62)&&(angle4<=75))&&((angle5>=65)&&(angle5<=86)))
//printfun('M');
//if(((angle1>=54)&&(angle1<=70))&&((angle2>=50)&&(angle2<=61))&&((angle3>=48)&&(angle3<=66))&&((angle4>=60)&&(angle4<=76))&&((angle5>=50)&&(angle5<=65))&&(((xadc>=400)&&(xadc<=435))&&((yadc>=350)&&(yadc<=390))))
//printfun('N');
if(((angle1>=40)&&(angle1<=88))&&((angle2>=68)&&(angle2<=90))&&((angle3>=40)&&(angle3<=80))&&((angle4>=54)&&(angle4<=80))&&((angle5>=40)&&(angle5<=80))){

  Serial.println('O');
printfun('O');
}
//if(((angle1>=60)&&(angle1<=75))&&((angle2>=60)&&(angle2<=85))&&((angle3>=0)&&(angle3<=10))&&((angle4>=0)&&(angle4<=15))&&((angle5>=30)&&(angle5<=55))&&(((xadc>=270)&&(xadc<=290))&&((yadc>=360)&&(yadc<=380))))
//printfun('P');
//if(((angle1>=75)&&(angle1<=90))&&((angle2>=75)&&(angle2<=90))&&((angle3>=65)&&(angle3<=90))&&((angle4>=0)&&(angle4<=15))&&((angle5>=0)&&(angle5<=30))&&(((xadc>=270)&&(xadc<=300))&&((yadc>=360)&&(yadc<=390))))
//printfun('Q');
//if(((angle1>=40)&&(angle1<=72))&&((angle2>=45)&&(angle2<=90))&&((angle3>=20)&&(angle3<=45))&&((angle4>=0)&&(angle4<=10))&&((angle5>=45)&&(angle5<=80))&&(((xadc>=412)&&(xadc<=418))&&((yadc>=340)&&(yadc<=360))))
//printfun('R');
if(((angle1>=70)&&(angle1<=90))&&((angle2>=80)&&(angle2<=90))&&((angle3>=70)&&(angle3<=90))&&((angle4>=80)&&(angle4<=90))&&((angle5>=30)&&(angle5<=60))){

  Serial.println('S');
printfun('S');
}
if(((angle1>=40)&&(angle1<=61))&&((angle2>=72)&&(angle2<=84))&&((angle3>=45)&&(angle3<=65))&&((angle4>=44)&&(angle4<=63))&&((angle5>=65)&&(angle5<=86))){
Serial.println('T');
  
printfun('T');
}
//if(((angle1>=70)&&(angle1<=90))&&((angle2>=80)&&(angle2<=90))&&((angle3>=0)&&(angle3<=10))&&((angle4>=0)&&(angle4<=10))&&((angle5>=60)&&(angle5<=80)))
//printfun('U');
//if(((angle1>=70)&&(angle1<=90))&&((angle2>=80)&&(angle2<=90))&&((angle3>=0)&&(angle3<=10))&&((angle4>=0)&&(angle4<=10))&&((angle5>=60)&&(angle5<=80))&&(digitalRead(6)==HIGH)) 
//printfun('V');
if(((angle1>=70)&&(angle1<=90))&&((angle2>=0)&&(angle2<=10))&&((angle3>=0)&&(angle3<=10))&&((angle4>=0)&&(angle4<=10))&&((angle5>=30)&&(angle5<=60))){
printfun('W');
Serial.println('W');
}
//if(((angle1>=50)&&(angle1<=72))&&((angle2>=45)&&(angle2<=90))&&((angle3>=35)&&(angle3<=75))&&((angle4>=80)&&(angle4<=89))&&((angle5>=45)&&(angle5<=80)))//&&!(((xadc>=412)&&(xadc<=418))&&((yadc>=340)&&(yadc<=360))))
//printfun('X');
if(((angle1>=0)&&(angle1<=20))&&((angle2>=70)&&(angle2<=90))&&((angle3>=60)&&(angle3<=90))&&((angle4>=80)&&(angle4<=90))&&((angle5>=0)&&(angle5<=20))){
Serial.println('Y');
  
 printfun('Y');
}

//if(((angle1>=50)&&(angle1<=72))&&((angle2>=45)&&(angle2<=90))&&((angle3>=35)&&(angle3<=75))&&((angle4>=0)&&(angle4<=10))&&((angle5>=45)&&(angle5<=80))&&(((xadc>=412)&&(xadc<=418))&&((yadc>=340)&&(yadc<=360))))
//printfun('Z');

//if(((angle1>=70)&&(angle1<=90))&&((angle2>=70)&&(angle2<=90))&&((angle3>=0)&&(angle3<=20))&&((angle4>=0)&&(angle4<=20))&&((angle5>=0)&&(angle5<=20))){
//Serial.println('3');
//  
// // printfun('3');
//}
//
//if(((angle1>=0)&&(angle1<=20))&&((angle2>=0)&&(angle2<=20))&&((angle3>=0)&&(angle3<=20))&&((angle4>=0)&&(angle4<=20))&&((angle5>=44)&&(angle5<=70))){
//Serial.println('4');
//  
// // printfun('4');
//}
//
//if(((angle1>=0)&&(angle1<=20))&&((angle2>=0)&&(angle2<=20))&&((angle3>=0)&&(angle3<=20))&&((angle4>=0)&&(angle4<=20))&&((angle5>=0)&&(angle5<=20))){
//Serial.println('5');
//  
// // printfun('5');
//}
//
//if(((angle1>=60)&&(angle1<=90))&&((angle2>=0)&&(angle2<=20))&&((angle3>=0)&&(angle3<=20))&&((angle4>=0)&&(angle4<=20))&&((angle5>=60)&&(angle5<=90))){
//Serial.println('6');
//  
// // printfun('6');
//}
//
//if(((angle1>=0)&&(angle1<=20))&&((angle2>=60)&&(angle2<=90))&&((angle3>=0)&&(angle3<=20))&&((angle4>=0)&&(angle4<=20))&&((angle5>=60)&&(angle5<=90))){
//Serial.println('7');
//  
// // printfun('7');
//}
//
//if(((angle1>=0)&&(angle1<=20))&&((angle2>=0)&&(angle2<=20))&&((angle3>=60)&&(angle3<=90))&&((angle4>=0)&&(angle4<=20))&&((angle5>=60)&&(angle5<=90))){
//Serial.println('8');
//  
// // printfun('8');
//}


delay(1500);

}
//----------------------END-----------------------------
