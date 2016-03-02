#include "Stdafx.h"
#include "Game.h"

int Game::InitAllegro(int _screenX, int _screenY)
{
  m_screenX = _screenX;
  m_screenY = _screenY;
 
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
}

//int Game::