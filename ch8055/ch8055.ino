#include "USBHIDKeyboard.h"

uint8_t dout;
uint8_t ain1,ain2;
uint8_t t;


void setup(){
pinMode(11,INPUT);
USBInit();
}


byte port[6]={14,15,17,31,30};

void loop() {
  ain1=analogRead(11);


t=0;
if(digitalRead(port[0]))t|=0x10;
if(digitalRead(port[1]))t|=0x20;
if(digitalRead(port[2]))t|=0x01;
if(digitalRead(port[3]))t|=0x40;
if(digitalRead(port[4]))t|=0x80;


 
 Keyboard_press(t,0,255-ain1,0);
 for(int i=0;i<5;i++){
 digitalWrite(port[i],(dout&(1<<i))?0:1);
 }
 
 delay(10);

}
