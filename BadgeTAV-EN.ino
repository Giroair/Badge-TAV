/*Code for a Badge for Tecnoateneu de Vilablareix.
 ATTiny85 based.
 It uses pins PB0 to PB3 to controll 12 LEDs using Charlieplexing technique.
Link to the schematic: http://www.technoblogy.com/show?1ONY
Link to implement a ATtiny85 programmer with Arduino: https://www.youtube.com/watch?v=BexXvxmOGN8
ledx(1,time)- turns On LED x and remains On for time indicated.
ledx(0,time)- turns Off LED x and remains Off for time indicated.
Copyleft Lluís Llimargas. Feel free to use or distribute, only mention to @Tecnoateneu and @LluísLlimargas is required.
 */

 #define PB0  0
 #define PB1  1
 #define PB2  2
 #define PB3  3

int i,j,time;    // various variables for loops and time management.

void setup() {
}


void loop() {
  alloff();

  // ------------effect 1
  // Di i D2 alterning.
  time=500;
  for (i=0;i<5;i++){
    led1(1,time);
    led1(0,0);
    led2(1,time);
    led2(0,0);
  }
  alloff();
  
  // ------------effect 2
  //Randomly turing On/Off LEDs.
  for(i=0;i< 50;i++){
    j=random(1,12);
    switch (j){
      case 1:
        led1(1,100);
        break;
      case 2:
        led2(1,100);
        break;
      case 3:
        led3(1,100);
        break;
      case 4:
        led4(1,100);
        break;
      case 5:
        led5(1,100);
        break;
      case 6:
        led6(1,100);
        break;
      case 7:
        led7(1,100);
        break;
      case 8:
        led8(1,100);
        break;
      case 9:
        led9(1,100);
        break;
      case 10:
        led10(1,100);
        break;
      case 11:
        led11(1,100);
        break;
      case 12:
        led12(1,100);
        break;    
    }
    alloff();
   }

  // ------------effect 3
  //Circular On/Off the LEDs.
  j=100; // waiting time in every LED (in milliseconds)
  for(i=0;i<5;i++){
    led11(1,j);
    led12(1,j);
    led8(1,j);
    led4(1,j);
    led6(1,j);
    led5(1,j);
    led3(1,j);
    led7(1,j);
  }
  for(i=0;i<5;i++){
    led1(1,j);
    led9(1,j);
    led10(1,j);
    led2(1,j);
  }

   

  // ------------efecte 4
  //Four LED Flash effect.
  time=30; // waiting time in every LED (in milliseconds)
  for(i=0;i<4;i++){
    for(j=0;j<6;j++){
      led1(1,time);
      led1(0,time);
    }
    for(j=0;j<6;j++){
      led2(1,time);
      led2(0,time);
    }    
    for(j=0;j<6;j++){
      led9(1,time);
      led9(0,time);
    }    
    for(j=0;j<6;j++){
      led10(1,time);
      led10(0,time);
    }    
  }

// ---------- Efecte 5
// Left to Right and back.
time=50;  // // waiting time in every LED (in milliseconds)
//lateral movement
for(i=0;i<5;i++){
  led3(1,time);
  led7(1,time);
  led5(1,time);  
  led9(1,time);
  led11(1,time);
  led1(1,time);
  led2(1,time);
  led12(1,time);  
  led10(1,time);  
  led8(1,time);
  led6(1,time);
  led4(1,time);  
  led6(1,time);
  led8(1,time);  
  led10(1,time);    
  led12(1,time); 
  led2(1,time);
  led1(1,time);  
  led11(1,time);
  led9(1,time);
  led5(1,time);
  led7(1,time);  
}

//vertical movement.
for(i=0;i<5;i++){
  led11(1,time);
  led12(1,time);
  led8(1,time);  
  led2(1,time);
  led1(1,time);
  led7(1,time);
  led3(1,time);
  led9(1,time);  
  led10(1,time);  
  led11(1,time);
  led6(1,time);
  led5(1,time);  
  led6(1,time);
  led4(1,time);  
  led10(1,time);    
  led9(1,time); 
  led3(1,time);
  led7(1,time);  
  led1(1,time);
  led2(1,time);
  led8(1,time);
  led12(1,time);  
}

} // End of main Loop.


// ===================================================================
void led1(int i,int time){
  pinMode(PB0,OUTPUT);
  pinMode(PB1,OUTPUT);
  pinMode(PB2,INPUT);
  pinMode(PB3,INPUT);
  if (i)
    digitalWrite(PB0,HIGH);
  else
    digitalWrite(PB0,LOW);
  digitalWrite(PB1,LOW);
  delay(time);
}

void led2(int i,int time){
  pinMode(PB0,INPUT);
  pinMode(PB1,OUTPUT);
  pinMode(PB2,OUTPUT);
  pinMode(PB3,INPUT);
  if (i)
    digitalWrite(PB2,HIGH);
  else
    digitalWrite(PB2,LOW);
  digitalWrite(PB1,LOW);
  delay(time);
}

void led3(int i,int time){
  pinMode(PB0,INPUT);
  pinMode(PB1,OUTPUT);
  pinMode(PB2,INPUT);
  pinMode(PB3,OUTPUT);
  if (i)
    digitalWrite(PB3,HIGH);
  else
    digitalWrite(PB3,LOW);
  digitalWrite(PB1,LOW);
  delay(time);
}

void led4(int i,int time){
  pinMode(PB0,OUTPUT);
  pinMode(PB1,OUTPUT);
  pinMode(PB2,INPUT);
  pinMode(PB3,INPUT);
  if (i)
    digitalWrite(PB1,HIGH);
  else
    digitalWrite(PB1,LOW);
  digitalWrite(PB0,LOW);
  delay(time);
}

void led5(int i,int time){
  pinMode(PB0,OUTPUT);
  pinMode(PB1,INPUT);
  pinMode(PB2,OUTPUT);
  pinMode(PB3,INPUT);
  if (i)
    digitalWrite(PB2,HIGH);
  else
    digitalWrite(PB2,LOW);
  digitalWrite(PB0,LOW);
  delay(time);
}

void led6(int i,int time){
  pinMode(PB0,OUTPUT);
  pinMode(PB1,INPUT);
  pinMode(PB2,INPUT);
  pinMode(PB3,OUTPUT);
  if (i)
    digitalWrite(PB3,HIGH);
  else
    digitalWrite(PB3,LOW);
  digitalWrite(PB0,LOW);
  delay(time);
}

void led7(int i, int time){
  pinMode(PB0,OUTPUT);
  pinMode(PB1,INPUT);
  pinMode(PB2,INPUT);
  pinMode(PB3,OUTPUT);
  if (i)
    digitalWrite(PB0,HIGH);
  else
    digitalWrite(PB0,LOW);
  digitalWrite(PB3,LOW);
  delay(time);
}

void led8(int i,int time){
  pinMode(PB0,INPUT);
  pinMode(PB1,OUTPUT);
  pinMode(PB2,INPUT);
  pinMode(PB3,OUTPUT);
  if (i)
    digitalWrite(PB1,HIGH);
  else
    digitalWrite(PB1,LOW);
  digitalWrite(PB3,LOW);
  delay(time);
}

void led9(int i,int time){
  pinMode(PB0,INPUT);
  pinMode(PB1,INPUT);
  pinMode(PB2,OUTPUT);
  pinMode(PB3,OUTPUT);
  if (i)
    digitalWrite(PB2,HIGH);
  else
    digitalWrite(PB2,LOW);
  digitalWrite(PB3,LOW);
  delay(time);
}

void led10(int i,int time){
  pinMode(PB0,OUTPUT);
  pinMode(PB1,INPUT);
  pinMode(PB2,OUTPUT);
  pinMode(PB3,INPUT);
  if (i)
    digitalWrite(PB0,HIGH);
  else
    digitalWrite(PB0,LOW);
  digitalWrite(PB2,LOW);
  delay(time);
}

void led11(int i,int time){
  pinMode(PB0,INPUT);
  pinMode(PB1,OUTPUT);
  pinMode(PB2,OUTPUT);
  pinMode(PB3,INPUT);
  if (i)
    digitalWrite(PB1,HIGH);
  else
    digitalWrite(PB1,LOW);
  digitalWrite(PB2,LOW);
  delay(time);
}

void led12(int i,int time){
  pinMode(PB0,INPUT);
  pinMode(PB1,INPUT);
  pinMode(PB2,OUTPUT);
  pinMode(PB3,OUTPUT);
  if (i)
    digitalWrite(PB3,HIGH);
  else
    digitalWrite(PB3,LOW);
  digitalWrite(PB2,LOW);
  delay(time);
}
void alloff(void){
  pinMode(PB0,OUTPUT);
  pinMode(PB1,OUTPUT);
  pinMode(PB2,OUTPUT);
  pinMode(PB3,OUTPUT);
  digitalWrite(PB0,LOW);
  digitalWrite(PB1,LOW);
  digitalWrite(PB2,LOW);
  digitalWrite(PB3,LOW);
}
