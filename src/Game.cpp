#include "Stdafx.h"
#include "Game.h"

int g_ticks = 0;

void Timer()
{
  g_ticks++;
}
END_OF_FUNCTION(Timer);

int Game::Init(int _screenX, int _screenY)
{
  m_done = false;
  m_screenX = _screenX;
  m_screenY = _screenY;
  m_fps = 60;
  g_ticks = 0;
  m_oldticks = 0;

  //If Allegro doesn't initialise, exit
  if (allegro_init() != 0)
  {
    return 1;
  }

  //Initialise Enemy
  //BITMAP* m_enemyBitmap = load_bitmap("enemy.bmp", NULL);
  /*if(m_enemyBitmap == NULL)
  {
    allegro_message("Failed to load image enemybitmap\n");
    return -1;
  }*/
  m_enemy = new Enemy(50, 50, "rob.bmp");

  //Initialise Player
  m_player = new Player();

  install_keyboard(); //Set up the keyboard
  if(install_mouse() == -1)
  {
    allegro_message("Cannot Initalise Mouse\n");
    return 1;
  }
  
  install_timer(); //Set up the timer

  //Creates the screen (Graphics mode). If it doesn't create, exit
  set_color_depth(32);
  if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, m_screenX, m_screenY, 0, 0)) {
    set_color_depth(24);
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, m_screenX, m_screenY, 0, 0)) {
      set_color_depth(16);
      if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, m_screenX, m_screenY, 0, 0)) {
        set_color_depth(15);
        if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, m_screenX, m_screenY, 0, 0)) {
          allegro_message("Video Error: %s.\n", allegro_error);
          return 1;
        }
      }
    }
  }

  // -- Sets the colour palette
  //set_palette(desktop_palette);
  m_buffer = create_bitmap(_screenX, _screenY);

  //Initialise Timer
  LOCK_VARIABLE(g_ticks);
  LOCK_FUNCTION(Timer);
  install_int_ex(Timer, BPS_TO_TIMER(m_fps));

  return 0;
}

void Game::Update()
{  
  int m_frame = 0;
  while(!m_done)
  {
    while(g_ticks == 0)
    {
      rest(1);
    }

    while(g_ticks > 0)
    {
      m_oldticks = g_ticks;
      //Updates section
      m_frame++;
      if(key[KEY_ESC])
      {
        m_done = true;
      }
      m_player->HandleCursorLocation();
      //End of Updates
      clear_to_color(m_buffer, makecol(50,50,50));
      g_ticks--;
      if(m_oldticks <= g_ticks) {break;}
    }
    //Render Section
    textprintf_ex(m_buffer, font, 10, 10, makecol(255, 255, 255), -1, "Current Frame: %i", m_frame);
    m_enemy->Render(m_buffer);
    //End of Rendering
    show_mouse(screen);
    blit(m_buffer, screen, 0, 0, 0, 0, m_screenX, m_screenY);
  }
}

void Game::Quit()
{
  
}