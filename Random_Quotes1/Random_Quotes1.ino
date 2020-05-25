#include <LiquidCrystal.h>
LiquidCrystal lcd1(12,11,5,4,3,2);

int b1In = 6;
int b1State;

int x=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd1.begin(16,2);  //16X2 LCD
pinMode(b1In, INPUT);
lcd1.print("hello!");
lcd1.setCursor(0,1);
lcd1.print("hello my name is willard!");

delay(1000);


}
void loop() {
  // put your main code here, to run repeatedly:
for(x; x<=9; x++){  //moves screen to the left
lcd1.scrollDisplayLeft();
delay(500);
}
for(x; x>=0; x--){ //moves screen to the right
lcd1.scrollDisplayRight();

}
}
