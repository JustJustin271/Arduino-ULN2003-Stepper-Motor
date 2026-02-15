int aPin = 8;
int cPin = 10;
int bPin = 9;
int dPin = 11;

int clockBtn = 2;
int counterBtn = 3;


//***Variables are adjustable***


int timeDelay = 500; //Lower -> Faster, Higher -> Slower, 3 - 7 is the sweet spot (t occurs 8 times in the loop, so time per universalLoop = 8t)

int localLoop = 0; //Defines it as 0

int universalLoop = 6; //How many times it will rotate.

void setup() {
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(clockBtn, INPUT_PULLUP);
  pinMode(counterBtn, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(clockBtn) == LOW) {
    
    while (true) {
      clockLoop ();
      localLoop++;
      if(localLoop == universalLoop) {
        shutOff ();
        localLoop = 0;
        break;
      }
    }
  } // This bracket was the bane of my existence ToT
  else if (digitalRead(counterBtn) == LOW) {
    
    while (true) {
      counterLoop (); 
      localLoop++;
      if(localLoop == universalLoop) {
        shutOff ();
        localLoop = 0;
        break;
      }
    }  
  }
 else {
    localLoop = 0;
    shutOff ();
 }  
}

void shutOff () {
  digitalWrite(aPin, LOW);
  digitalWrite(bPin, LOW);
  digitalWrite(cPin, LOW);
  digitalWrite(dPin, LOW);
}

void clockLoop () {
  // A
      digitalWrite(aPin,HIGH);
      digitalWrite(bPin,LOW);
      digitalWrite(cPin,LOW);
      digitalWrite(dPin,LOW);
      delay(timeDelay);
      
      // AC
      digitalWrite(aPin,HIGH);
      digitalWrite(bPin,LOW);
      digitalWrite(cPin,HIGH);
      digitalWrite(dPin,LOW);
      
      delay(timeDelay);
      
      // C
      digitalWrite(aPin,LOW);
      digitalWrite(bPin,LOW);
      digitalWrite(cPin,HIGH);
      digitalWrite(dPin,LOW);
  
      delay(timeDelay);
      
      // CB
      digitalWrite(aPin,LOW);
      digitalWrite(bPin,HIGH);
      digitalWrite(cPin,HIGH);
      digitalWrite(dPin,LOW);
  
      delay(timeDelay);
      
      // B
      digitalWrite(aPin,LOW);
      digitalWrite(bPin,HIGH);
      digitalWrite(cPin,LOW);
      digitalWrite(dPin,LOW);
  
      delay(timeDelay);
      
      // BD
      digitalWrite(aPin,LOW);
      digitalWrite(bPin,HIGH);
      digitalWrite(cPin,LOW);
      digitalWrite(dPin,HIGH);
  
      delay(timeDelay);
      
      // D
      digitalWrite(aPin,LOW);
      digitalWrite(bPin,LOW);
      digitalWrite(cPin,LOW);
      digitalWrite(dPin,HIGH);
  
      delay(timeDelay);
      
      // DA
      digitalWrite(aPin,HIGH);
      digitalWrite(bPin,LOW);
      digitalWrite(cPin,LOW);
      digitalWrite(dPin,HIGH);
      
      delay(timeDelay);
}

void counterLoop () {

  // DA
      digitalWrite(aPin,HIGH);
      digitalWrite(bPin,LOW);
      digitalWrite(cPin,LOW);
      digitalWrite(dPin,HIGH);
      
      delay(timeDelay);

  // D
      digitalWrite(aPin,LOW);
      digitalWrite(bPin,LOW);
      digitalWrite(cPin,LOW);
      digitalWrite(dPin,HIGH);
  
      delay(timeDelay);

  // BD
      digitalWrite(aPin,LOW);
      digitalWrite(bPin,HIGH);
      digitalWrite(cPin,LOW);
      digitalWrite(dPin,HIGH);
  
      delay(timeDelay);

  // B
      digitalWrite(aPin,LOW);
      digitalWrite(bPin,HIGH);
      digitalWrite(cPin,LOW);
      digitalWrite(dPin,LOW);
  
      delay(timeDelay);

  // CB
      digitalWrite(aPin,LOW);
      digitalWrite(bPin,HIGH);
      digitalWrite(cPin,HIGH);
      digitalWrite(dPin,LOW);
  
      delay(timeDelay);

  // C
      digitalWrite(aPin,LOW);
      digitalWrite(bPin,LOW);
      digitalWrite(cPin,HIGH);
      digitalWrite(dPin,LOW);
  
      delay(timeDelay);

  // AC
      digitalWrite(aPin,HIGH);
      digitalWrite(bPin,LOW);
      digitalWrite(cPin,HIGH);
      digitalWrite(dPin,LOW);
      
      delay(timeDelay);

  
  // A
      digitalWrite(aPin,HIGH);
      digitalWrite(bPin,LOW);
      digitalWrite(cPin,LOW);
      digitalWrite(dPin,LOW);
  
      delay(timeDelay);          
}

//Feburary 10th, 2026
//By Justin 
//This is Arduino code for the ULN2003 stepper motor for an engineering project 
//This was a lot of lines of code and prob should have done my Dr. Racket HW
//I do need to learn about arrays and the "i" thingy in C++, but on the weekend tbh
