/*
  LEDHSV.cpp - Implements the LEDHSV class.
  Created by Jesse R. Castro 2013-05-06 01:10:41
  This file was created by the Generator Tool!
*/
#include "LEDHSV.h"
LEDHSV::LEDHSV() {
	init(-1,-1,-1,0.0,0.0,0.0,false,false);
}
LEDHSV::LEDHSV(const LEDHSV& pLEDHSV){
	*this = pLEDHSV;
}
LEDHSV::LEDHSV(int pRedPin, int pGreenPin, int pBluePin, float pHue, float pSaturation, float pBrightness, bool pAutoSend, bool pAnode) {
	init(pRedPin, pGreenPin, pBluePin, pHue, pSaturation, pBrightness, pAutoSend, pAnode);
}
LEDHSV::LEDHSV(int pRedPin, int pGreenPin, int pBluePin, bool pAutoSend/* = false */, bool pAnode/* = false */) {
	init(pRedPin, pGreenPin, pBluePin, 0.0,0.0,0.0, pAutoSend, pAnode);
}
LEDHSV::~LEDHSV(){

}
void LEDHSV::init(int pRedPin, int pGreenPin, int pBluePin, float pHue, float pSaturation, float pBrightness, bool pAutoSend, bool pAnode) {
	//always want the state to start in false since we know we won't be turning it on in the constructor
	setState(false);
	//note, we set autoSend to false always here so that we don't send the LED any values when we construct
	setAutoSend(false);
	setPins(pRedPin, pGreenPin, pBluePin);
	setHSV(pHue, pSaturation, pBrightness);
	setAutoSend(pAutoSend);
	setAnode(pAnode);
	setup();
}
void LEDHSV::setRedPin(int pRedPin){
	redPin = pRedPin;
}
void LEDHSV::setGreenPin(int pGreenPin){
	greenPin = pGreenPin;
}
void LEDHSV::setBluePin(int pBluePin){
	bluePin = pBluePin;
}
void LEDHSV::setRedValue(int pRedValue){
	if(pRedValue > 255){
		redValue = 255;
	}else if(pRedValue < 0){
		redValue = 0;
	}else{
		redValue = pRedValue;
	}
}
void LEDHSV::setGreenValue(int pGreenValue){
	if(pGreenValue > 255){
		greenValue =  255;
	}else if(pGreenValue < 0){
		greenValue = 0;
	}else{
		greenValue = pGreenValue;
	}
}
void LEDHSV::setBlueValue(int pBlueValue){
	if(pBlueValue > 255){
		blueValue =  255;
	}else if(pBlueValue < 0){
		blueValue = 0;
	}else{
		blueValue = pBlueValue;
	}
}
void LEDHSV::setHue(float pHue, bool pSetAfter/* = true */){
	pHue = abs(pHue);
	if(pHue > 1){
		float floorVal = floor(pHue);
		hue = pHue - floorVal;
	}else{
		hue = pHue;
	}
	if(pSetAfter){
		HSV2RGB();
	}
}
void LEDHSV::setSaturation(float pSaturation, bool pSetAfter/* = true */){
	pSaturation = abs(pSaturation);
	if(pSaturation > 1){
		float floorVal = floor(pSaturation);
		saturation = pSaturation - floorVal;
	}else{
		saturation = pSaturation;
	}
	if(pSetAfter){
		HSV2RGB();
	}
}
void LEDHSV::setBrightness(float pBrightness, bool pSetAfter/* = true */){
	pBrightness = abs(pBrightness);
	if(pBrightness > 1){
		float floorVal = floor(pBrightness);
		brightness = pBrightness - floorVal;
	}else{
		brightness = pBrightness;
	}
	if(pSetAfter){
		HSV2RGB();
	}
}
void LEDHSV::setAutoSend(bool pAutoSend){
	autoSend = pAutoSend;
}
void LEDHSV::setState(bool pState){
	state = pState;
}
void LEDHSV::setAnode(bool pAnode){
	anode = pAnode;
}
int LEDHSV::getRedPin(){
	return redPin;
}
int LEDHSV::getGreenPin(){
	return greenPin;
}
int LEDHSV::getBluePin(){
	return bluePin;
}
int LEDHSV::getRedValue(){
	return redValue;
}
int LEDHSV::getGreenValue(){
	return greenValue;
}
int LEDHSV::getBlueValue(){
	return blueValue;
}
float LEDHSV::getHue(){
	return hue;
}
float LEDHSV::getSaturation(){
	return saturation;
}
float LEDHSV::getBrightness(){
	return brightness;
}
bool LEDHSV::getAutoSend(){
	return autoSend;
}
bool LEDHSV::getState(){
	return state;
}
bool LEDHSV::getAnode(){
	return anode;
}
void LEDHSV::setPins(int pRedPin, int pGreenPin, int pBluePin){
	setRedPin(pRedPin);
	setGreenPin(pGreenPin);
	setBluePin(pBluePin);
}
void LEDHSV::off(){
	setState(false);
	setRGB(0,0,0);
}
void LEDHSV::on(){
	setState(true);
	HSV2RGB();
}
void LEDHSV::send(){
	if(
		(redPin != -1)&&
		(bluePin != -1)&&
		(greenPin != -1)
	){
		if(
			(redValue == 0)&&
			(greenValue == 0)&&
			(blueValue == 0)
		){
			//if we're sending all zeroes, then the LED is off
			setState(false);
		}
		analogWrite(redPin, redValue);
		analogWrite(greenPin, greenValue);
		analogWrite(bluePin, blueValue);
	}else{
		//we're not on if we haven't set pin values yet
		setState(false);
	}
}
void LEDHSV::setup(){
	if(
		(redPin != -1)&&
		(bluePin != -1)&&
		(greenPin != -1)
	){
		pinMode(redPin, OUTPUT);
		pinMode(greenPin, OUTPUT);
		pinMode(bluePin, OUTPUT);
	}
}
void LEDHSV::setHSV(float pHue, float pSaturation, float pBrightness){
	setHue(pHue, false);
	setSaturation(pSaturation, false);
	setBrightness(pBrightness);
}
void LEDHSV::setRGB(int pRedValue, int pGreenValue, int pBlueValue){
	if(anode){
		setRedValue(255 - pRedValue);
		setGreenValue(255 - pGreenValue);
		setBlueValue(255 - pBlueValue);
	}else{
		setRedValue(pRedValue);
		setGreenValue(pGreenValue);
		setBlueValue(pBlueValue);
	}
	if(autoSend){
		send();
	}
}
void LEDHSV::HSV2RGB(){
	float r, g, b;

	float h = hue;
	float s = saturation;
	float v = brightness;
	
	int i = floor(h * 6);
	float f = h * 6 - i;
	float p = v * (1 - s);
	float q = v * (1 - f * s);
	float t = v * (1 - (1 - f) * s);

	switch(i % 6){
		case 0: r = v, g = t, b = p; break;
		case 1: r = q, g = v, b = p; break;
		case 2: r = p, g = v, b = t; break;
		case 3: r = p, g = q, b = v; break;
		case 4: r = t, g = p, b = v; break;
		case 5: r = v, g = p, b = q; break;
	}

	setRGB(round(r*255),round(g*255),round(b*255));
}
LEDHSV& LEDHSV::operator=(const LEDHSV &pLEDHSV){
	if(this != &pLEDHSV){
		redPin		= pLEDHSV.redPin;
		greenPin	= pLEDHSV.greenPin;
		bluePin		= pLEDHSV.bluePin;
		redValue	= pLEDHSV.redValue;
		greenValue	= pLEDHSV.greenValue;
		blueValue	= pLEDHSV.blueValue;
		hue			= pLEDHSV.hue;
		saturation	= pLEDHSV.saturation;
		brightness	= pLEDHSV.brightness;
		autoSend	= pLEDHSV.autoSend;
		anode		= pLEDHSV.anode;
		state		= pLEDHSV.state;
	}
	return *this;
}
bool LEDHSV::operator==(const LEDHSV &pLEDHSV) const {
	if(
		(redValue == pLEDHSV.redValue)&&
		(greenValue == pLEDHSV.greenValue)&&
		(blueValue == pLEDHSV.blueValue)&&
		(hue == pLEDHSV.hue)&&
		(saturation == pLEDHSV.saturation)&&
		(brightness == pLEDHSV.brightness)&&
		(autoSend == pLEDHSV.autoSend)&&
		(anode == pLEDHSV.anode)&&
		(state == pLEDHSV.state)
	){
		return true;
	}else{
		return false;
	}
}
bool LEDHSV::operator!=(const LEDHSV &pLEDHSV) const {
	return !(*this == pLEDHSV);
}
