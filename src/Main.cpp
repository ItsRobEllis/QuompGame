#include "Stdafx.h"
void GameClose();

int main(int argc, char* args[])
{
    //If Allegro doesn't initialise, exit
  if (allegro_init() != 0)
  {
    return 1;
  }

  //Set up the keyboard
  install_keyboard(); 

  //Creates the screen (Graphics mode). If it doesn't create, exit
  if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, m_screenX, m_screenY, 0, 0) != 0)
  {
    if (set_gfx_mode(GFX_SAFE, m_screenX, m_screenY, 0, 0) != 0)
    {
      set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
      allegro_message("Unable to create screen\n%s\n", allegro_error);
      return 1;
    }
  }

  //Sets the colour palette
  set_palette(desktop_palette);

  //Clear to white
  clear_to_color(screen, makecol(255, 255, 255));
 
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