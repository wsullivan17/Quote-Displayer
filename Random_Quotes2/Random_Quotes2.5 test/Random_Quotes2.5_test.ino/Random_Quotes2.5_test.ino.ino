#include <LiquidCrystal.h>
LiquidCrystal lcd1(12,11,5,4,3,2);

int b1In = 7;
int b1State;


int x=0;
//no more than 44 characters
String message[] = {"____", "Greetings! A B C D E F G H I J K L M N O P Q R S ", "What's your problem? I was taking a nap!", "Good morning... what time is it?"};

int messageSize = (sizeof(message))/6; //calculates amount of quotes in message[].... was in multibles of 6 for some reason

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd1.begin(16,2);  //16X2 LCD
pinMode(b1In, INPUT);




}

void loop() {
  // put your main code here, to run repeatedly:
b1State = digitalRead(b1In);
//Serial.print(b1State);
delay(100);
//Serial.println("_");
//Serial.println(x);  //testing

if(b1State == HIGH){
  x = x+1;  //moves onto the next quote

  if(x >= messageSize){
  x = 0;
  lcd1.clear();
  lcd1.print("The last Quote!");
  delay(1500);
}

  lcd1.clear();
  delay(500);   //sets up for new quote
  String quote = message[x];
  int quoteLength = quote.length();   //calculates the length of the new quote

  if(quoteLength<=16){      //if quote<=16 characters, quote printed onto top line
  lcd1.print(message[x]);
  delay(1500);              //time quote is displayed
  lcd1.clear();
  }

  else if(quoteLength>16){  //if the quote is larger than 16 characters  JUST HAVE THE TEXT MOVE!!
    
  char over16[quoteLength];   //new character array
  //message[x].toCharArray(over16, quoteLength);  //converts string array (message) into character array (over16)
  int moveQuoteLeft;
  int moveQuoteRight;
  int quoteLengthMinus = quoteLength-16;  //calculates the amount the text has to move so the whole quote can be seen
  int moveCount = 0;
  lcd1.clear();
  
while(moveCount<1){

  lcd1.print(message[x]);
  delay(500);
  
    for(moveQuoteLeft = 0; moveQuoteLeft<=quoteLengthMinus; moveQuoteLeft++){
  
      lcd1.scrollDisplayLeft();
      delay(250);
    }
  delay(500);
    for(moveQuoteRight = quoteLengthMinus; moveQuoteRight >= -1; moveQuoteRight--){

      lcd1.scrollDisplayRight();
      delay(50);
    }
    
  
  lcd1.clear();
  //Serial.println(moveCount); for testing
  moveCount = moveCount+1;
}
 
}



}



else if(b1State == LOW){
  lcd1.print("The Quote... ");
}
//else if( ){
  //when the number of quotes has been reached, reset "x"
}
  
