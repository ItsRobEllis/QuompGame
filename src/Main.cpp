#include "Stdafx.h"
void GameClose();

int main(int argc, char* args[])
{
  
 
  //Print to the center of the window
  textout_centre_ex(screen, font, "Hello, world!", SCREEN_W/2, SCREEN_H/2, makecol(0,0,0), -1);
 
  //Release the screen
  release_screen();

  //Run the function when the close button is clicked
  set_close_button_callback(GameClose);
 
  //Wait for keypress
  readkey();
  return 0;
}

END_OF_MAIN()