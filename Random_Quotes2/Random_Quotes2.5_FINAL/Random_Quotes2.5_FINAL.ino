#include <LiquidCrystal.h>
LiquidCrystal lcd1(12,11,5,4,3,2);

int b1In = 7;
int b1State;
int scrollSpeed = 300;

int x=0;
//no more than 40 characters
String message[] = {"____", "Greetings!", "Hello there...         General Kenobi! ", "Check out The Eric Andre Show on Hulu!", "What in tarnation!", "Sorry...", "Yes, no, maybe...   I don't know...", 
                    "What do YOU want? Leave me alone!", "I'm a little robot, short and stout...", "Stop pushing my buttons!", "You coexist with Danny DeVito!", "What is this place?", "Hey! What are you looking at?",
                   "Good morning... what time is it?", "Subscribe to Pewdiepie.", "I don't understand this world.", "Gahhhhhhhhhhhh!", "Press F to pay respects", "Walking sounds fun.",
                    "Am I an allusion?", "Where should I go to college?", "Im in it to win it!", "I have no chance in winning...", "What's your problem?I was taking a nap!", "Computers are cool",
                    "Contrary to popular belief, I am God.","Huh?", "I can change cases like a hermit crab.", "Saturn is my favorite planet!", "WHO is Willard?", "I met a penguin once.", ": - 0", "Bill Nye the Science Guy!",
                    "Windows Troubleshooter is not helpful.", "Beep. Boop. Bleep." };


                                      

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
delay(100);

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
      delay(scrollSpeed);
    }
  delay(500);
    for(moveQuoteRight = quoteLengthMinus; moveQuoteRight >= -1; moveQuoteRight--){

      lcd1.scrollDisplayRight();
      delay(50);
    }
    
 
  delay(50);
  lcd1.clear();
  //Serial.println(moveCount); for testing
  moveCount = moveCount+1;
}
 
}



}



else if(b1State == LOW){
  lcd1.print("The Quote... ");
}
}
  
