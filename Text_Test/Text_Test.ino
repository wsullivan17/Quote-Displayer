#include <LiquidCrystal.h>
LiquidCrystal lcd1(12,11,5,4,3,2);

int x;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
lcd1.print("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ");


while(1==1){
lcd1.scrollDisplayLeft();
delay(300);
}


}
