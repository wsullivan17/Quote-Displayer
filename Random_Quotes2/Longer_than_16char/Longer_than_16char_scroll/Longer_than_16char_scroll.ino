#include <LiquidCrystal.h>
LiquidCrystal lcd1(12,11,5,4,3,2);

int b1In = 7;
int b1State;


int x=0;

String message[] = {"hello", "general", "kenobiabcdefghijklmn", "WHO GOES THERE WHAT IN TARNATION!!!!", "SORRY..."};

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
  x = x+1;  //moves onto the next quote
  lcd1.clear();
  delay(500);   //sets up for new quote
  String quote = message[x];
  int quoteLength = quote.length();   //calculates the length of the new quote

  if(quoteLength<=16){      //if quote<=16 characters, quote printed onto top line
  lcd1.print(message[x]);
  delay(1000);  //time message is displayed
  lcd1.clear();
  delay(300);
  lcd1.print("Goodbye.........");
  lcd1.setCursor(0,1);      //moves cursor onto the next line for further printing
  lcd1.print("................");
  delay(500);
  lcd1.clear();
  delay(500);
  }

  else if(quoteLength>16){  //if the quote is larger than 16 characters  JUST HAVE THE TEXT MOVE!!
  char over16[quoteLength];  //new character array
  //message[x].toCharArray(over16, quoteLength);  //converts string array (message) into character array (over16)
  int moveQuoteLeft;
  int quoteLengthMinus = quoteLength-16;  //calculates the amount the text has to move so the whole quote can be seen
  int moveCount;
  lcd1.clear();
  lcd1.print(" ");
  lcd1.print(message[x]);
  delay(500);
  
// while(moveCount<3){
     
    for(moveQuoteLeft=0; moveQuoteLeft<=quoteLengthMinus +1; moveQuoteLeft++){
  lcd1.scrollDisplayLeft();
  delay(500);
  }
  lcd1.clear();
  Serial.println(moveCount);
  moveCount = moveCount+1;
// }
 
  }
}



else if(b1State == LOW){
  lcd1.print("The Quote... ");
}
//else if( ){
  //when the number of quotes has been reached, reset "x"
}
  
