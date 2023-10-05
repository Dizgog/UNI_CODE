// Simon game
// by Mark Lawry


int maxCount = 20;  //max number in random sequence
int rndSeq[50] ;
int debounceDelay = 30;


const int ledPin1 = 8;
const int ledPin2 = 9;
const int ledPin3 = 10;
const int ledPin4 = 11;

const int button1 = 4;
const int button2 = 5;
const int button3 = 6;
const int button4 = 7;

int iCount;
int iiCount;
int highScore = 0;
int score = 0;

int freq[4] = {196, 220, 247, 262};
int seqDuration = 250; // tone length
int seqDelay = 350;   //delay while LED seq played
int replayDelay = 1500; //delay before playing next sequence
int button;

void setup() 
{
pinMode(ledPin1, OUTPUT);  
pinMode(ledPin2, OUTPUT);  
pinMode(ledPin3, OUTPUT); 
pinMode(ledPin4, OUTPUT); 
  
pinMode(button1, INPUT_PULLUP);
pinMode(button2, INPUT_PULLUP);
pinMode(button3, INPUT_PULLUP);
pinMode(button4, INPUT_PULLUP);
  
Serial.begin(9600);
}

void loop()
{
  
//generate random sequence
int randomStart = analogRead(A3);
  randomSeed(randomStart);
  Serial.println(randomStart);
  for (int count =0 ; count < maxCount ; count++)
  {rndSeq[count] = random(1,5);
  }
//print the sequence
  for (int count =0 ; count <maxCount ; count++)
  {Serial.print(rndSeq[count]);
  }  
  Serial.println();
  Serial.println();
    
// play the game until correctResponse is false, or maxCount reached  
  boolean correctResponse = true;
//start with 1 note, then build sequence
  int loopCount = 0;          
  while (loopCount < maxCount) 
  {
  iCount = 0;
    score = loopCount+1;
    while (iCount <= loopCount)  //play sequence up to loopCount    
    {
     button = rndSeq[iCount];
     Serial.print(button);  //print the correct sequence for debugging
     digitalWrite(ledPin1, LOW);  
     digitalWrite(ledPin2, LOW);
     digitalWrite(ledPin3, LOW);  
     digitalWrite(ledPin4, LOW);
     
  if (button == 1) 
     {digitalWrite(ledPin1, HIGH);
     delay(seqDelay);
     digitalWrite(ledPin1, LOW);
     delay(50);}
  if (button == 2) 
     {digitalWrite(ledPin2, HIGH);
     delay(seqDelay);
     digitalWrite(ledPin2, LOW);
     delay(50);}
  if (button == 3) 
     {digitalWrite(ledPin3, HIGH);
     delay(seqDelay);
     digitalWrite(ledPin3, LOW);
     delay(50);}
  if (button == 4) 
     {digitalWrite(ledPin4, HIGH);
     delay(seqDelay);
     digitalWrite(ledPin4, LOW);
     delay(50);} 
     iCount = iCount+1; 
    }   // End of played sequence
    
// Listen for user replay sequence  
    Serial.println( ); 
    Serial.println("Enter your response: "); 
    iiCount = 0;
    
  while (iiCount <= loopCount) {
    digitalWrite(ledPin1, LOW);  
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);  
    digitalWrite(ledPin4, LOW);
 
//Test for button 1 being pressed
  if (digitalRead(button1) == LOW ) 
    {button = 1;
    if (button==rndSeq[iiCount]) 
      {correctResponse = true;
      digitalWrite(ledPin1, HIGH); 
      delay(debounceDelay); 
      iiCount=iiCount+1;     } 
    else 
      {correctResponse=false;
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
      delay(seqDuration);
      iiCount=999;
      }    
    while (digitalRead(button1) == LOW ) // wait until button release
      {delay(debounceDelay);} 
    digitalWrite(ledPin1, LOW); 
    }
   
//Test for button 2 being pressed   
  if (digitalRead(button2) == LOW )
    {button = 2;
    if (button==rndSeq[iiCount]) 
      {correctResponse = true;  
      digitalWrite(ledPin2, HIGH); 
      delay(debounceDelay);          
      iiCount=iiCount+1;
      } 
    else 
      {correctResponse=false;
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
      delay(seqDuration);
      iiCount=999;
      }    
    while (digitalRead(button2) == LOW ) // wait until button release
      {delay(debounceDelay);}  
    digitalWrite(ledPin2, LOW);    
    }
  
//Test for button 3 being pressed    
  if (digitalRead(button3) == LOW )
    {button = 3;
    if (button==rndSeq[iiCount]) 
      {correctResponse = true;
       digitalWrite(ledPin3, HIGH); 
       delay(debounceDelay);
       iiCount=iiCount+1;
       }          
    else 
      {correctResponse=false;
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
      delay(seqDuration);
      iiCount=999;
      }  
    while (digitalRead(button3) == LOW ) // wait until button release
      {delay(debounceDelay);} 
    digitalWrite(ledPin3, LOW);
    } 
    
//Test for button 4 being pressed   
  if (digitalRead(button4) == LOW )
    {button = 4;
    if (button==rndSeq[iiCount]) 
      {correctResponse = true;
      digitalWrite(ledPin4, HIGH); 
      delay(debounceDelay);          
      iiCount=iiCount+1;     
      } 
    else 
      {correctResponse=false;
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
      delay(seqDuration);
      iiCount=999;
      }  
    while (digitalRead(button4) == LOW ) // wait until button release
      {delay(debounceDelay);} 
    digitalWrite(ledPin4, LOW);
    }
//If correctResponse is false, set the counts high to exit the loop
    if (correctResponse==false) 
    {iiCount= 999; iCount=999; 
    loopCount = 111;
    Serial.println("Wrong one.");
    }                        
  }   //end of user response loop         
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
         
   delay(replayDelay); 
   loopCount = loopCount+1;  //add one note to sequence
  }  //end of main loopCount loop -------------------

// game end, the user either finished the sequence, or made a wrong resonse

if(correctResponse==true)
{
  Serial.println("Winner!");
} 
else 
{
  Serial.println("Sorry");
  score = score-1;
}
  // Game over.------------------

   Serial.print("Score = ");Serial.println(score);
   Serial.println("game over - restarting");
   delay(2500);
}


void beepStart()
{
int toneFreq = 100;
  for(int i=1; i<12; i++)
{
    digitalWrite(ledPin1, HIGH);  
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);  
    digitalWrite(ledPin4, HIGH);
   delay(100);
    digitalWrite(ledPin1, LOW);  
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);  
    digitalWrite(ledPin4, LOW);
   delay(100);
   toneFreq= float(toneFreq)*1.12;
}
}