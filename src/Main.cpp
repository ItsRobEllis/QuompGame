#include "Stdafx.h"

int main()
{
  Game *game = new Game;
  game->Init(1024, 768); //Initialise Allegro4 & classes
  game->Update(); //The main game loop
  game->Quit(); //Unloads everything gracefully
  return 0;
}

END_OF_MAIN()