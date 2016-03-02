#include "Stdafx.h"

int main()
{
  Game *game = new Game;
  game->InitAllegro(1024, 768);

  //game->ChangeGameState(MENU);
 
  //Release the screen
  release_screen();
 
  //Wait for keypress
  readkey();
  return 0;
}

END_OF_MAIN()