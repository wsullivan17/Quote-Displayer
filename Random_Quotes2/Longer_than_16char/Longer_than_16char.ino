#include <LiquidCrystal.h>
LiquidCrystal lcd1(12,11,5,4,3,2);

int b1In = 7;
int b1State;


int x=0;

String message[] = {"general", "kenobi", "WHO GOES THERE WHAT IN TARNATION!!!!", "SORRY...jaddfjdsffkds", "qwertyuiopasdfghjkl"};

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd1.begin(16,2);  //16X2 LCD
pinMode(b1In, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
b1State = digitalRead(b1In);
delay(100);


if(b1State == HIGH){
  x = x+1;  //moves onto the next quote
  lcd1.clear();
  delay(500);   //sets up for new quote
  String quote = message[x];
  int quoteLength = quote.length();   //calculates the length of the new quote

  if(quoteLength<=16){      //if quote<=16 characters, quote printed onto top line
  lcd1.print(message[x]);
  delay(500);  //time message is displayed
  lcd1.clear();
  }

  else if(quoteLength>16){  //if the quote is larger than 16 characters
  char over16[quoteLength];  //new character array
  message[x].toCharArray(over16, quoteLength);  //converts string array (message) into character array (over16)

lcd1.setCursor(0,0);
  for(int under16 = -1; under16<=15; under16++){
    lcd1.print(over16[under16]);
    lcd1.setCursor(under16+1,0);
    Serial.print(over16[under16]);
  }
  
lcd1.setCursor(0,1);

  for(int greater16 = 16; greater16<=31; greater16++){
   int greater16ShiftStart = 0;
   int greater16Shift = greater16ShiftStart+1;
   
   lcd1.print(over16[greater16]);
   lcd1.setCursor(greater16Shift+1,1);
   Serial.print(over16[greater16]); 
  }
   delay(2000);
   lcd1.clear();
  }
}



else if(b1State == LOW){
  lcd1.print("The Quote... ");
}

}
