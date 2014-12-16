/*
  RUN.pde
 
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

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}

// Global variables go here...

/*
Point mazeArray[24row][24column] =
{
  _
}
*/

Point mazeArray[10][10] =
{
  {0,0,0,1,1,1,1,0},  // sample, yo.
  {1,1,1,0,0,0,1,1},
  
}

// below: DrawPx (x,y,screen[x][y]}


void drawScreen()
{
 DrawPx(1,1,Green);
 DrawPx(1,2,Green);
 
for (int i = 0; i < 576; i++)
  {
    if (mazeArray[i].x >= 0 &&
        mazeArray[i].x <= 7 &&
        mazeArray[i].y >= 0 &&
        mazeArray[i].y <= 7)
    {
      DrawPx(mazeArray[i].x, mazeArray[i].y, Green);
    }
  }
}

void loop()
{
  DrawPx(2,2,Yellow);  // PLAYER
  
  DrawPx(3,10,Red);  // OBSTACLES
  DrawPx(3,11,Red);
  DrawPx(18,10,Red);
  DrawPx(18,11,Red);
  DrawPx(19,14,Red);
  DrawPx(19,15,Red);
  DrawPx(19,16,Red);
  DrawPx(22,16,Red);
  DrawPx(22,17,Red);
  DrawPx(23,1,Red);
  DrawPx(23,2,Red);
  DrawPx(23,3,Red);
  DrawPx(23,4,Red);
  DrawPx(23,5,Red);
  DrawPx(23,9,Red);
  DrawPx(23,10,Red);
  
  drawScreen();
  
  DisplaySlate();
  delay(125);
  ClearSlate();
}
  
