//
// BBombe.cpp for BBomb.cpp in /home/zoukie/Desktop/epitech/cpp_indie_studio/src/Objects
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Mon May 22 20:17:22 2017 
// Last update Thu Jun 22 05:01:57 2017 
//

# include "BBomb.hh"
# include "irrKlang.h"

BBomb::BBomb(int range, int idPlayer, float height, float weidth, std::vector< std::vector< Objects *> > map) : Objects(height, weidth)
{
  logs->Out("BBomb", "init Bomb.");
  type = 3;
  this->mesh = smgr->getMesh("images/cube.obj");
  this->nodeBomb = smgr->addAnimatedMeshSceneNode( mesh, 0, -1,
					       irr::core::vector3df(0, 0, 0),
					       irr::core::vector3df(0, 0, 0),
					       irr::core::vector3df(0.705, 0.705, 0.705));

  Blist.push_back(this);
  _range = range;
  _idPlayer = idPlayer;
  x = (int)height;
  y = (int)weidth;
  _map = map;
  logs->Out("BBomb", "Affichage Bomb xd.");
  SetAff();
  _startTime = device->getTimer()->getTime();
}

BBomb::~BBomb()
{
  if (this->nodeBomb)
    this->nodeBomb->remove();
}

void	BBomb::SetAff()
{
  if (this->nodeBomb)
    {
      this->nodeBomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      this->nodeBomb->setMD2Animation(irr::scene::EMAT_STAND);
      this->nodeBomb->setPosition(irr::core::vector3df(this->x, this->y, 0));
      this->nodeBomb->setMaterialTexture( 0, driver->getTexture("images/bomb.png") );
    }
}

void BBomb::DeleteCube(int x, int y)
{
    if (x > 0 && y > 0 && x <= 19 && y <= 19)
    {
      // if (_map[x][y]->type != 1)
      // 	Fire *lavaFire = new Fire(x, y);
      if (this->_map[x][y]->type == 2)
	{
	  this->_map[x][y]->UnSetAff();
	  delete this->_map[x][y];
	  this->_map[x][y] = new Empty(x, y);
	}
    }
}

int	BBomb::Explode()
{
  int	range;

  range = 0;
  logs->Out("BBomb", "Boom ?");
  if (device->getTimer()->getTime() >= _startTime + 2000)
    {
      while (range <= _range)
	{
	  this->DeleteCube(x + range, y);
	  this->DeleteCube(x, y + range);
	  this->DeleteCube(x - range, y);
	  this->DeleteCube(x, y - range);
	  ++range;
	}
      logs->Out("BBomb", "Bomb exploded.");
      irrklang::ISoundEngine* engine = irrklang::createIrrKlangDevice();  
     if (!engine)
      return 0;
    engine->play2D("media/bomb.ogg", false);
      return (1);
    }
  return (0);
}

void	BBomb::UnSetAff()
{
  if (nodeBomb)
    nodeBomb->remove();
}
