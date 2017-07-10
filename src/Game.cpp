//
// Game.cpp for  in /home/beche/cpp_indie_studio/src
// 
// Made by beche
// Login   <francois.beche@epitech.eu>
// 
// Started on  Wed Jun  7 18:55:46 2017 beche
// Last update Thu Jun 22 05:42:06 2017 
//

# include "irrlicht.h"
# include "IrrlichtDevice.h"

# include <list>
# include "Game.hh"

Game::Game(int x, int y)
{
  this->device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(x, y),
			      16, false, false, false, 0);
  this->guienv = device->getGUIEnvironment();
  this->context = new SAppContext(this->guienv);
  GamePaused = 0;
}

Map*	Game::CreateMap(int a)
{
  this->map = new Map(a);
  this->map->GenerateMap();
  return (this->map);
}
