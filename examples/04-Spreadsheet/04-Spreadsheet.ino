/** MIT License
*
* Copyright(c) 2017 DevDuino
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files(the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions :
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

//Include board with DevDuino components.
#include <devduino.h>

//DevDuino logo to display a splash screen before example.
#include <devduinoLogo.h>

//Initialize program.
void setup()
{
  //First thing to do is to initialize DevDuino board.
  devduino.begin();

  //Attach "interrupt" button to "buttonPressed" function.
  devduino.attachToIntButton(buttonPressed);
  
  //Draw splash screen to buffer.
  display.drawSprite(devduinoLogo, 37, 0);
  //Then transfer buffer to screen.
  display.flush();
  
  //Sleep for 1 second with splash screen displayed to be able to see it before continuing.
  delay(1000);
  
  //Erase splash screen from display buffer. No need to flush right now, we will flush on next drawing operation.
  display.clear();

  //Automatically draw borders on cells.
  spreadsheet.enableDrawBorders(true);
  
  //Display text in specified cells of spreadsheet.
  spreadsheet.print(0, "Default grid have");
  spreadsheet.print(1, "1 column");
  spreadsheet.print(2, "and");
  spreadsheet.print(3, "4 lines.");
}

//runExample is set to true when button is pressed.
bool runExample = false;

//Loop over program execution.
void loop()
{
  //If we must run example.
  if(runExample) {
    //Configure a custom grid of 5 lines and 2 columns.
    spreadsheet.setGrid(5, 2);

    //Print text in each cell of spreadsheet.
    spreadsheet.print(0, "Areas");
    spreadsheet.print(1, "can");
    spreadsheet.print(2, "be");
    spreadsheet.print(3, "configured");
    spreadsheet.print(4, "and");
    spreadsheet.print(5, "accessed");
    spreadsheet.print(6, "using");
    spreadsheet.print(7, "a");
    spreadsheet.print(8, "single");
    spreadsheet.print(9, "index");

    //No need to run example forever, it has just been displayed to screen.
    runExample = false;
  }
}

//This method has been bound to "INT" button of DevDuino board in the above "setup" method.
void buttonPressed()
{
  //Run the second example defined in loop.
  runExample = true;
}

