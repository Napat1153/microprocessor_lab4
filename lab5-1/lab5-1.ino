#include<SPI.h>
#define DATA_PIN 11
#define CLOCK_PIN 13
#define SS_PIN 9
#define SS1_PIN 10
int c[10]=
{
   0b00111111, //0
   0b00000110, //1
   0b01011011, //2
   0b01001111, //3
   0b11100110, //4
   0b01101101, //5
   0b01111101, //6
   0b00100111, //7
   0b01111111, //8
   0b01101111, //9
};
int count=0;
void setup()
{
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(10,OUTPUT);

}

void loop()
{
  for(count=1;count<10;count++)
  {
    for(int i=0;i<10;i++)
    {
    digitalWrite(SS1_PIN,LOW);
    digitalWrite(SS_PIN,LOW);
    shiftOut(DATA_PIN,CLOCK_PIN,MSBFIRST,c[i]);  
    digitalWrite(SS1_PIN,HIGH);
    delay(500);
    } 
  shiftOut(DATA_PIN,CLOCK_PIN,MSBFIRST,c[count]);  
  digitalWrite(SS_PIN,HIGH);
  }
  delay(500);
  digitalWrite(SS_PIN,LOW);
  shiftOut(DATA_PIN,CLOCK_PIN,MSBFIRST,c[0]);  
  digitalWrite(SS_PIN,HIGH);
}
