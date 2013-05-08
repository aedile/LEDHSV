#include <LEDHSV.h>
//these are common anode
boolean commonAnode = true;
//rpin,gpin,bpin,autosend,anode
LEDHSV Led1(24,25,26,true,commonAnode);
LEDHSV Led2(1,0,27,true,commonAnode);
LEDHSV Led3(14,15,16,true,commonAnode);

int ButtonPin = 17;
void setup(){
  pinMode(ButtonPin, INPUT_PULLUP);
}
float Hue = 0.0;
float masterBrightness = 1;
float Brightness = masterBrightness;
float Saturation = 1;
void loop(){
    //when the button is pressed, turn LED 1 off immediately
    //pull the saturation on LED2 down to 0 (full white)
    //pull the brightness on LED3 down to 0 (off)
    if (digitalRead(ButtonPin) == LOW) {
        Brightness = Brightness - (masterBrightness/1000);
        Saturation = Saturation - 0.001;
        if(Brightness < 0){
           Brightness = 0; 
        }
        if(Saturation < 0){
           Saturation = 0; 
        }
        Led1.off();
	Led2.setHSV((Hue+0.333),Saturation,masterBrightness);
	Led3.setHSV((Hue+0.666),1,Brightness);
    //when the button is released, turn LED 1 on immediately
    //bring the saturation on LED2 up to 1 (full color)
    //bring the brightness on LED3 up to masterBrightness (on, full brightness for sketch)
    //Loop through the hue wheel, offset each new LED by 1/3
   }else{  
   	Brightness = Brightness + (masterBrightness/1000);
        Saturation = Saturation + 0.001;
        if(Brightness > masterBrightness){
           Brightness = masterBrightness; 
        }
        if(Saturation > 1){
           Saturation = 1; 
        }
        Led1.setHSV(Hue,1,masterBrightness);
	Led2.setHSV((Hue+0.333),Saturation,masterBrightness);
	Led3.setHSV((Hue+0.666),1,Brightness);
	delay(10);
        Hue = Hue + 0.001;
        if(Hue >=1)Hue=0;
  }
}