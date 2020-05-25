#include <LiquidCrystal.h>
LiquidCrystal lcd1(12,11,5,4,3,2);

int b1In = 7;
int b1State;


int x=0;

char* message[] = {"hello", "generalxyz", "ken"};

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd1.begin(16,2);  //16X2 LCD
pinMode(b1In, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
b1State = digitalRead(b1In);
Serial.print(b1State);
delay(100);
Serial.println("_");
Serial.println(x);

if(b1State == HIGH){
  x = x+1;
  String quote = message[x];
  int quoteLength = quote.length(); 
  lcd1.clear();
  delay(500);
  lcd1.print(quoteLength);
  delay(1000);
  lcd1.print(message[x]);
  delay(2000);
}



else if(b1State == LOW){
  lcd1.print("The Quote... ");
}

}
