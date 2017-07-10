//
// Game.hh for  in /home/beche/cpp_indie_studio/include
// 
// Made by beche
// Login   <francois.beche@epitech.eu>
// 
// Started on  Wed Jun  7 18:56:21 2017 beche
// Last update Thu Jun 22 05:42:26 2017 
//

#ifndef GAME_HH_
# define GAME_HH_

# include "irrlicht.h"
# include "IrrlichtDevice.h"

# include <iostream>
# include <string>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <list>

# include "Base.hh"
# include "Map.hh"
# include "Player.hh"
# include "Save.hh"
# include "EventReceiver.hh"
# include "Context.hh"

class	Game
{
public:
  Game(int, int);
  ~Game();
  
  Map				*CreateMap(int);
  irr::IrrlichtDevice		*device;
  irr::gui::IGUIEnvironment	*guienv; 
  Map				*map;
  Player			*player;
  Save				*save;
  SAppContext			*context;
  int				GamePaused;
};  
#endif /* !PLAYER_HH_ */
