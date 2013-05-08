/*
  LEDHSV.h - Defines the LEDHSV class.
  Created by Jesse R. Castro 2013-05-06 01:10:40
  This file was created by the Generator Tool!
*/
#ifndef LEDHSV_h
#define LEDHSV_h

#include "Arduino.h"

/** 
 * Represents a physical LED and allows you to control it via HSV color space
 * @author Jesse R. Castro
 * @version %I%, %G% 
*/
class LEDHSV
{
	public:
		/**
		 * Default class constructor for initializing with no values.
		 * @author Jesse R. Castro
		 */
		LEDHSV();
		/**
		 * Copy class constructor for initializing with another instance of this class.
		 * @author Jesse R. Castro
		 * @param pLEDHSV An instance of the same type as this object.
		 */
		LEDHSV(const LEDHSV& pLEDHSV);
		/**
		 * Class constructor for initializing with individual parameters.
		 * @author Jesse R. Castro
		 * @param pRedPin An int value with the address of the red leg of the LED.
		 * @param pGreenPin An int value with the address of the green leg of the LED.
		 * @param pBluePin An int value with the address of the blue leg of the LED.
		 * @param pHue A float value representing the color of the LED.
		 * @param pSaturation A float value representing the Saturation of the color of the LED.
		 * @param pBrightness A float value representing the brightness of the LED.
		 * @param pAutoSend A boolean value representing whether to automatically send the RGB values to the physical LED when private method setRGB is called.
		 * @param pAnode A boolean value representing whether the LED is common anode or cathode
		 */
		LEDHSV(int pRedPin, int pGreenPin, int pBluePin, float pHue, float pSaturation, float pBrightness, bool pAutoSend, bool pAnode);
		/**
		 * Class constructor for initializing with only pins and optionally the autoSend and anode flags (useful if you just want to initialize and setup without any color info).
		 * @author Jesse R. Castro
		 * @param pRedPin An int value with the address of the red leg of the LED.
		 * @param pGreenPin An int value with the address of the green leg of the LED.
		 * @param pBluePin An int value with the address of the blue leg of the LED.
		 * @param pAutoSend A boolean value representing whether to automatically send the RGB values to the physical LED when private method setRGB is called.
		 * @param pAnode A boolean value representing whether the LED is common anode or cathode
		 */
		LEDHSV(int pRedPin, int pGreenPin, int pBluePin, bool pAutoSend = false, bool pAnode = false);
		/**
		 * Class destructor for destroying the class when it falls out of scope.  This method currently doesn't do anything.
		 * @author Jesse R. Castro
		 */
		~LEDHSV();
		/**
		 * Setter method for internal variable hue.
		 * @author Jesse R. Castro
		 * @param pHue A float value to set internal private variable Hue, which represents the hue of the LED from 0-1.
		 * @param pSetAfter A boolean value that determines whether to set the RGB values after.  Defaults to true.
		 */
		void setHue(float pHue, bool sendAfter = true);
		/**
		 * Setter method for internal variable saturation.
		 * @author Jesse R. Castro
		 * @param pSaturation A float value to set internal private variable Saturation, which represents the saturation of the LED from 0-1.
		 * @param pSetAfter A boolean value that determines whether to set the RGB values after.  Defaults to true.
		 */
		void setSaturation(float pSaturation, bool sendAfter = true);
		/**
		 * Setter method for internal variable brightness.
		 * @author Jesse R. Castro
		 * @param pBrightness A float value to set internal private variable Brightness, which represents the brightness of the LED from 0-1.
		 * @param pSetAfter A boolean value that determines whether to set the RGB values after.  Defaults to true.
		 */
		void setBrightness(float pBrightness, bool sendAfter = true);
		/**
		 * Setter method for internal variable autoSend.
		 * @author Jesse R. Castro
		 * @param pAutoSend A bool value to set internal private variable AutoSend, which represents whether to automatically send the RGB values to the physical LED when private method setRGB is called.
		 */
		void setAutoSend(bool pAutoSend);
		/**
		 * Getter method for internal variable redPin.
		 * @author Jesse R. Castro
		 * @return The value of internal private variable RedPin, which represents pin address of the red leg of the LED.
		 */
		int getRedPin();
		/**
		 * Getter method for internal variable greenPin.
		 * @author Jesse R. Castro
		 * @return The value of internal private variable GreenPin, which represents pin address of the green leg of the LED.
		 */
		int getGreenPin();
		/**
		 * Getter method for internal variable bluePin.
		 * @author Jesse R. Castro
		 * @return The value of internal private variable BluePin, which represents pin address of the blue leg of the LED.
		 */
		int getBluePin();
		/**
		 * Getter method for internal variable redValue.
		 * @author Jesse R. Castro
		 * @return The value of internal private variable RedValue, which represents the value to send to the red leg of the LED from 0-255.
		 */
		int getRedValue();
		/**
		 * Getter method for internal variable greenValue.
		 * @author Jesse R. Castro
		 * @return The value of internal private variable GreenValue, which represents the value to send to the green leg of the LED from 0-255.
		 */
		int getGreenValue();
		/**
		 * Getter method for internal variable blueValue.
		 * @author Jesse R. Castro
		 * @return The value of internal private variable BlueValue, which represents the value to send to the blue leg of the LED from 0-255.
		 */
		int getBlueValue();
		/**
		 * Getter method for internal variable hue.
		 * @author Jesse R. Castro
		 * @return The value of internal private variable Hue, which represents the hue of the LED from 0-1.
		 */
		float getHue();
		/**
		 * Getter method for internal variable saturation.
		 * @author Jesse R. Castro
		 * @return The value of internal private variable Saturation, which represents the saturation of the LED from 0-1.
		 */
		float getSaturation();
		/**
		 * Getter method for internal variable brightness.
		 * @author Jesse R. Castro
		 * @return The value of internal private variable Brightness, which represents the brightness of the LED from 0-1.
		 */
		float getBrightness();
		/**
		 * Getter method for internal variable autoSend.
		 * @author Jesse R. Castro
		 * @return The value of internal private variable AutoSend, which represents whether to automatically send the RGB values to the physical LED when private method setRGB is called.
		 */
		bool getAutoSend();
		/**
		 * Getter method for internal variable state.
		 * @author Jesse R. Castro
		 * @return The value of internal private variable State, which represents whether the led is on or not.
		 */
		bool getState();
		/**
		 * Getter method for internal variable anode.
		 * @author Jesse R. Castro
		 * @return The value of internal private variable anode, which represents whether the LED is common cathode or anode.
		 */
		bool getAnode();
		/**
		 * Turn the led off without losing the current HSV values
		 * @author Jesse R. Castro
		 */
		void off();
		/**
		 * Turn the led on with current values
		 * @author Jesse R. Castro
		 */
		void on();
		/**
		 * Sends the actual value to the RGB pins.  This is a virtual function so users can redefine functionality if they want extend the class.  Default functionality is to just send to pin values.  
		 * @author Jesse R. Castro
		 */
		virtual void send();
		/**
		 * set all three HSV values at once
		 * @author Jesse R. Castro
		 * @param pHue A float value to set internal private variable Hue, which represents the color of the LED from 0-1.
		 * @param pSaturation A float value to set internal private variable Saturation, which represents the saturation of the color of the LED from 0-1.
		 * @param pBrightness A float value to set internal private variable Brightness, which represents the brightness of the LED from 0-1.
		 */
		void setHSV(float pHue, float pSaturation, float pBrightness);
		/**
		 * Assignment operator overload.
		 * @author Jesse R. Castro
		 * @param pLEDHSV An instance of the same type as this object.
		 * @return This object (after it has been duplicated to the pLEDHSV parameter).
		 */
		LEDHSV& operator=(const LEDHSV &pLEDHSV);
		/**
		 * Comparison == operator overload.  Compares all values EXCEPT the pin values.
		 * @author Jesse R. Castro
		 * @param pLEDHSV An instance of the same type as this object.
		 * @return A bool value describing whether the objects are equivalent or not.
		 */
		bool operator==(const LEDHSV &pLEDHSV) const;
		/**
		 * Comparison != operator overload.
		 * @author Jesse R. Castro
		 * @param pLEDHSV An instance of the same type as this object.
		 * @return A bool value describing the inverse of whether the objects are equivalent or not.
		 */
		bool operator!=(const LEDHSV &pLEDHSV) const;
	protected:
		/**
		 * pin address of the red leg of the LED
		 */
		int redPin;
		/**
		 * pin address of the green leg of the LED
		 */
		int greenPin;
		/**
		 * pin address of the blue leg of the LED
		 */
		int bluePin;
		/**
		 * the value to send to the red leg of the LED from 0-255
		 */
		int redValue;
		/**
		 * the value to send to the green leg of the LED from 0-255
		 */
		int greenValue;
		/**
		 * the value to send to the blue leg of the LED from 0-255
		 */
		int blueValue;
		/**
		 * the hue of the LED from 0-1
		 */
		float hue;
		/**
		 * the saturation of the LED from 0-1
		 */
		float saturation;
		/**
		 * the brightness of the LED from 0-1
		 */
		float brightness;
		/**
		 * whether or not to automatically send values to the LED when calling internal function setRGB
		 */
		bool autoSend;
		/**
		 * whether or not the led is on
		 */
		bool state;
		/**
		 * whether or not the LED is common anode, determines values
		 */
		bool anode;
		/**
		 * Initialization method to cut down on constructor copy-pasta.
		 * @author Jesse R. Castro
		 * @param pRedPin An int value with the address of the red leg of the LED.
		 * @param pGreenPin An int value with the address of the green leg of the LED.
		 * @param pBluePin An int value with the address of the blue leg of the LED.
		 * @param pHue A float value representing the color of the LED.
		 * @param pSaturation A float value representing the Saturation of the color of the LED.
		 * @param pBrightness A float value representing the brightness of the LED.
		 * @param pAutoSend A boolean value representing whether to automatically send the RGB values to the physical LED when private method setRGB is called.
		 * @param pAnode A boolean value representing whether the led is common anode or cathode
		 */
		void init(int pRedPin, int pGreenPin, int pBluePin, float pHue, float pSaturation, float pBrightness, bool pAutoSend, bool pAnode);
		/**
		 * performs setup functions in place of the setup() routine in an arduino sketch
		 * @author Jesse R. Castro
		 */
		void setup();
		/**
		 * Converts HSV values to RGB colorspace, which is used by RGB LEDs
		 * @author Jesse R. Castro
		 */
		void HSV2RGB();
		/**
		 * set all three RGB values at once
		 * @author Jesse R. Castro
		 * @param pRed A float value to set internal private variable Hue, which represents the color of the LED from 0-1.
		 * @param pGreen A float value to set internal private variable Saturation, which represents the saturation of the color of the LED from 0-1.
		 * @param pBlue A float value to set internal private variable Brightness, which represents the brightness of the LED from 0-1.
		 */
		void setRGB(int pRedValue, int pGreenValue, int pBlueValue);
		/**
		 * set all three LED pins at once
		 * @author Jesse R. Castro
		 * @param pRedPin An integer value to set internal variable redPin, which represents the red leg of the LED
		 * @param pGreenPin An integer value to set internal variable greenPin, which represents the green leg of the LED
		 * @param pBluePin An integer value to set internal variable bluePin, which represents the green leg of the LED
		 */
		void setPins(int pRedPin, int pGreenPin, int pBluePin);
		/**
		 * Setter method for internal variable state.
		 * @author Jesse R. Castro
		 * @param pState A bool value to set internal private variable State, which represents whether the led is on or off
		 */
		void setState(bool pState);
		/**
		 * Setter method for internal variable anode.
		 * @author Jesse R. Castro
		 * @param pState A bool value to set internal private variable Anode, which represents whether the LED is common anode
		 */
		void setAnode(bool pAnode);
		/**
		 * Setter method for internal variable redPin.
		 * @author Jesse R. Castro
		 * @param pRedPin An int value to set internal private variable RedPin, which represents pin address of the red leg of the LED.
		 */
		void setRedPin(int pRedPin);
		/**
		 * Setter method for internal variable greenPin.
		 * @author Jesse R. Castro
		 * @param pGreenPin An int value to set internal private variable GreenPin, which represents pin address of the green leg of the LED.
		 */
		void setGreenPin(int pGreenPin);
		/**
		 * Setter method for internal variable bluePin.
		 * @author Jesse R. Castro
		 * @param pBluePin An int value to set internal private variable BluePin, which represents pin address of the blue leg of the LED.
		 */
		void setBluePin(int pBluePin);
		/**
		 * Setter method for internal variable redValue.
		 * @author Jesse R. Castro
		 * @param pRedValue An int value to set internal private variable RedValue, which represents the value to send to the red leg of the LED from 0-255.
		 */
		void setRedValue(int pRedValue);
		/**
		 * Setter method for internal variable greenValue.
		 * @author Jesse R. Castro
		 * @param pGreenValue An int value to set internal private variable GreenValue, which represents the value to send to the green leg of the LED from 0-255.
		 */
		void setGreenValue(int pGreenValue);
		/**
		 * Setter method for internal variable blueValue.
		 * @author Jesse R. Castro
		 * @param pBlueValue An int value to set internal private variable BlueValue, which represents the value to send to the blue leg of the LED from 0-255.
		 */
		void setBlueValue(int pBlueValue);

};
#endif
