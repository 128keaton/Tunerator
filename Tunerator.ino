#include "Arduboy.h"

Arduboy arduboy;
  
void setup()
{
  arduboy.begin();
  arduboy.setTextSize(1);
  arduboy.print("Push Buttons to Begin");
  arduboy.setCursor(0,0);
}


int byte1 = random(0, 5000);
int len = random(0, 5000);


bool fourth = true;

void loop ()
{
  // pause render until it's time for the next frame
  arduboy.setTextSize(4);
  arduboy.setCursor(0,0);
  if (arduboy.pressed(UP_BUTTON)) {
    byte1+=10;

  } else if (arduboy.pressed(DOWN_BUTTON)) {
    byte1-=10;

  } else if (arduboy.pressed(LEFT_BUTTON)) {
     len-=10;

  } else if (arduboy.pressed(RIGHT_BUTTON)) {
     len+=10;
   

  }
 
  if (arduboy.pressed(A_BUTTON)) {
    //randomize
    byte1 = random(0, 5000);
    len = random(0, 5000);
  } else if (arduboy.pressed(B_BUTTON)) {
    len = random(1000, 1500);
    fourth = !fourth;
    delay(100);
    arduboy.setRGBled(255, 0, 255);
  } else if (fourth == false){
    configureLED(2);
  }


      arduboy.clearDisplay();
       arduboy.setTextSize(1.5);
       if (fourth == true){
        configureLED(1);
        arduboy.print("Tone 1: " + String(byte1) + "\n" +  "Tone 2: " + String(len) + "\n\nMode:\nextra bits");
       }else{
        configureLED(2);
         arduboy.print("Tone 1: " + String(byte1) + "\n" +  "Tone 2: " + String(len) + "\n\nMode:\nrandomized");
       }
    arduboy.display();
  
playTune(byte1, len);

}
void configureLED(int color){
  switch (color){
    //blue
    case 1:
        arduboy.setRGBled(0, 0, 0);
        arduboy.setRGBled(255, 0, 0);
        break;

     //red
    case 2:
        arduboy.setRGBled(0, 0, 0);
        arduboy.setRGBled(0, 0, 255);
        break;
   
    
  }
  
}

void playTune(int first, int second){
  arduboy.tunes.tone(first, 1000);
  delay(20);
  arduboy.tunes.tone(second, 1000);
  delay(12);
  if(fourth == true){
    arduboy.tunes.tone(second/2, first);
    delay(12);
    arduboy.tunes.tone(second, first/2);
    delay(12);
  }

}

