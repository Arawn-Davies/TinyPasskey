/*
ATTiny85 TinyPasskey USB HID keyboard
*/
 
#include <TrinketKeyboard.h>

int led = 1;
 
void setup()
{
  pinMode(led, OUTPUT);
  // start USB stuff
  TrinketKeyboard.begin();
  // Assuming you've got a power LED on pin 1, this is to see whether the keyboard is active. 
  // Simply press Reset if you want to re-run.
  digitalWrite(led, HIGH);
  
  TrinketKeyboard.poll();
  // Wait for 5ms, to ensure that keypresses aren't lost
  delay(5);
  // type out a string using the Print class
  TrinketKeyboard.print("John Smith, ");
  digitalWrite(led, LOW);
}
 
void loop()
{
  // the poll function must be called at least once every 10 ms
  // or cause a keystroke
  // if it is not, then the computer may think that the device
  // has stopped working, and give errors
  TrinketKeyboard.poll();
  delay(8);
}
