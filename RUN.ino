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
  MeggyJrSimpleSetup();    // Required code, line 2 of 2.
  Serial.begin(9600); 
}

// Global variables go here...
int i = 0;

/*
Point mazeArray[24row][24column] =
{
  {#,#<#...#},
  {#,#...
}
*/

int mazeArray[12][12] =
{
  {0,0,0,0,0,0,0,0,0,0,0,0},  // maze
  {0,4,4,4,4,0,4,4,4,4,4,4},
  {0,4,0,0,4,0,4,0,0,0,0,0},
  {0,4,0,0,4,0,4,0,0,0,0,0},
  {0,4,0,0,4,0,4,0,0,4,4,4},
  {0,4,0,0,4,0,4,0,0,4,0,0},
  {0,4,0,0,4,0,4,0,0,4,0,0},
  {0,4,0,0,4,0,4,0,0,4,4,4},
  {0,4,0,0,4,0,4,0,0,0,0,0},
  {0,4,0,0,4,0,4,0,0,0,0,0},
  {0,4,0,1,4,0,4,4,4,4,4,4},
  {4,0,1,4,0,0,0,0,0,0,0,4},
  
};

// below: DrawPx (x,y,screen[x][y]}
void drawMaze()
{
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





void loop()                     // run over and over again
{
  DrawPx(2,2,Yellow);  // PLAYER
  drawMaze();
  DisplaySlate();
}
