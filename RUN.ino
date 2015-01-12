/*
  RUN.pde
  
  
   DIRECTIONS TO PLAY:
       - Use the control pad to switch directions
           
  
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Blink a damned LED.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */

 
 
 
 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

// INITIALIZE
int mazeArray[25][28] =
{
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,0,0,0},  // maze
  {0,4,4,4,4,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},  // but it is flipped
  {0,4,0,0,4,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,4},  // and rotated 90ª to the right
  {0,4,0,0,4,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,4},  // ;-;
  {0,4,0,0,4,0,4,0,0,4,4,4,4,4,4,4,4,4,0,0,4,4,0,1,4,0,0,4},
  {0,4,0,0,4,0,4,0,0,4,0,0,0,0,0,0,0,4,0,0,4,4,0,1,4,0,1,4},
  {0,4,0,0,4,0,4,0,0,4,0,0,0,0,0,0,0,4,0,0,4,4,0,0,4,0,1,4},
  {0,4,0,0,4,0,4,0,0,4,4,4,4,4,4,0,0,4,0,0,4,4,0,0,4,12,0,4},
  {0,4,0,0,4,0,4,0,0,0,0,0,0,0,4,0,0,4,0,0,4,4,0,0,4,4,4,4},
  {0,4,0,0,4,0,4,0,0,0,0,0,0,0,4,0,0,4,0,0,4,4,0,1,4,0,0,0},
  {0,4,0,1,4,0,4,4,4,4,4,4,0,0,4,0,0,4,1,0,4,4,0,1,4,0,0,0},
  {0,4,0,1,4,0,0,0,0,0,0,4,0,0,4,0,0,4,1,0,4,4,0,0,4,0,0,0},
  {0,4,0,0,4,0,0,0,0,0,0,4,0,0,4,0,0,4,0,0,4,4,0,0,4,0,0,0},
  {0,4,0,0,4,4,4,4,4,4,4,4,0,0,4,0,0,4,0,0,4,4,0,0,4,0,0,0},
  {0,4,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,4,0,1,4,4,0,0,4,0,0,0},
  {0,4,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,4,0,1,4,4,0,0,4,0,0,0},
  {0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,0,4,0,1,4,4,1,0,4,0,0,0},
  {0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,0,4,4,1,0,4,0,0,0},
  {0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,4,0,0,0},
  {0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,4,0,0,0},
  {0,4,0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,0,4,0,0,0},
  {0,4,0,0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,0,4,0,0,0},
  {0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0},
  {0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0},
  {0,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0}

};

int offsetX = 0;  //player's distance from starting point
int offsetY = 0;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();    // Required code, line 2 of 2.
  Serial.begin(9600); 
}

// Global variables go here...



void loop()                     // run over and over again
{ 
  ClearSlate();
  for (int i = 0; i < 7; i++)  // to only display what's within the screen...
  {
    for (int j = 0; j < 7; j++)
    {
      int x = i + offsetX;    // the PLAYER'S position in regard to the array
      int y = j + offsetY;
     
      DrawPx(i,j, mazeArray[x][y]);  // to display the array
    }
  }
  
  DrawPx(2,2,Yellow);  // draw PLAYER over background
  DisplaySlate();
  
  CheckButtonsPress();  // w/ help from Mr. Kiang
        // for descriptions of what buttons do, see Button_Right
  
  if (Button_Right)
  {
    if (ReadPx(3,2) == 0)  // if space to the right is "empty"
    {
      offsetX++;    // move to the right
    }
    else
    if (ReadPx(3,2) == 1)
    {
      Tone_Start(ToneD3, 250);
    }
    else
    if (ReadPx(3,2) == 4)
    {
      Tone_Start(ToneD3, 250);
    }
    else
    if (ReadPx (3,2) == 12)
    {
      offsetX++;
      Tone_Start(ToneG4,250);
      while (MakingSound) {}
      delay(25);
      Tone_Start(ToneA4,150);
      while (MakingSound) {}
      delay(25);
      Tone_Start(ToneG4,150);
      while (MakingSound) {}
      delay(25);
      Tone_Start(ToneD5,450);
      while (MakingSound) {}
      delay(50);
      // got above searching for a catchy theme to play on the meggy
          //http://individual.utoronto.ca/owlman9000/meggyjr/meggyjr_reverse_game.pde
      
      for (int x=0; x < 8; x++)
      {
        DisplaySlate();
        for (int i=0; i < 8; i++)
        {
          if ((i % 2) == 0)
          {
             if ((x % 2) != 0)
             {
                DrawPx(i,x,FullOn);
                DisplaySlate();
                delay(50); 
              }
              else
                {
                  DrawPx(i,x,Blue);
                  DisplaySlate();
                  delay(50);
                 }
                    
          }
          else
          {
            DrawPx(i,x,Green);
            DisplaySlate();
            delay(50);
          }
        }
      }
     
    }
  }
  if (Button_Left)
  {
    if (ReadPx(1,2) == 0)
    {
    offsetX--;
    }
    else
    if (ReadPx(1,2) == 1)
    {
      Tone_Start(ToneD3, 250);
    }
    else
    if (ReadPx(1,2) == 4)
    {
      Tone_Start(ToneD3, 250);
    }
  }
  if (Button_Up)
  {
    if (ReadPx (2,3) == 0)
    {
    offsetY++;
    }
    else
    if (ReadPx (2,3) == 1)
    {
      Tone_Start(ToneD3, 250);
    }
    else
    if (ReadPx (2,3) == 4)
    {
      Tone_Start(ToneD3, 250);
    }
  }
  if (Button_Down)
  {
    if (ReadPx (2,1) == 0)
    {
    offsetY--;
    }
    else
    if (ReadPx (2,1) == 1)
    {
      Tone_Start(ToneD3, 250);
    }
    else
    if (ReadPx (2,1) == 4)
    {
      Tone_Start(ToneD3, 250);
    }
  }
  
}
