//
// attributes_char.cpp for attributes in /home/oem/home/cpp_indie_studio/Maxence
// 
// Made by maxence.lauque
// Login   <lauque_m@epitech.net>
// 
// Started on  Mon May 29 16:10:12 2017 maxence.lauque
// Last update Thu Jun 22 05:28:43 2017 
//

#include "Player.hh"

Player::Player(int new_idplayer, Map *Map, float new_x, float new_y)
  : _life(true), _nb_bombs(1), _range(1), _speed(1)
{
  irr::scene::IAnimatedMesh *bomber = smgr->getMesh("imgs/tris.md2");

  _map = Map->getMap();
  _size_map = Map->getTaille();
  _id_player = new_idplayer;
  _x = new_x;
  _y = new_y;
  _nb_bombs = 100000;
  _col = smgr->getSceneCollisionManager();
  _bomb_used = 0;
  _nodeAnim = smgr->addAnimatedMeshSceneNode(bomber);
  if (_nodeAnim)
    {
      _nodeAnim->setRotation(irr::core::vector3df(-90, 0, -90));
      _nodeAnim->setPosition(irr::core::vector3df(_x, _y , 0));
      if (new_idplayer == 1)
	_nodeAnim->setMaterialTexture(0, driver->getTexture("imgs/Bomber.PCX"));
      else
	_nodeAnim->setMaterialTexture(0, driver->getTexture("imgs/Mexican.pcx"));
      _nodeAnim->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      _nodeAnim->setScale(irr::core::vector3df(0.025f, 0.025f, 0.025f));
      _nodeAnim->setFrameLoop(400, 600);
      _nodeAnim->setAnimationSpeed(30);
    }
}

Player::Player()
{
}

Player::~Player()
{
}

int	Player::get_IdPlayer()const
{
  return(this->_id_player);
}

void	Player::set_IdPlayer(int new_id)
{
  _id_player = new_id;
}

float	Player::get_x()const
{
  return(this->_x);
}

void	Player::set_x(float new_x)
{
  _x = new_x;
}

float	Player::get_y()const
{
  return(this->_y);
}

void	Player::set_y(float new_y)
{
  _y = new_y;
}

bool	Player::get_life()const
{
  return(this->_life);
}

void	Player::set_life(bool new_life)
{
  _life = new_life;
}

int	Player::get_nbBombs()const
{
  return (this->_nb_bombs);
}

void	Player::set_nbBombs(int new_nbBombs)
{
  _nb_bombs = new_nbBombs;
}

int	Player::get_range()const
{
  return (this->_range);
}

void	Player::set_range(int new_range)
{
  _range = new_range;
}

int	Player::get_speed()const
{
  return(this->_speed);
}

void	Player::set_speed(int new_speed)
{
  _speed = new_speed;
}

void	Player::DropBomb()
{
  if (_bomb_used < _nb_bombs)
    {
      if (_map[_x][_y]->type == 0)
	{
	  logs->Out("Player", "A player just dropped a Bomb.");
 	  _map[_x][_y]->addObject(new BBomb(_range, _id_player, _x, _y , _map));
	  _bomb_used++;
	}
    }
}

void  Player::SetPosition(float x, float y, std::string op)
{
  if (op == "+"){
    if (x > 0){
      if (_map[(this->_x+x)+0.7][this->_y] != NULL){            
	if (_map[(this->_x+x)+0.7][this->_y]->type != 1 && _map[(this->_x+x)+0.7][this->_y]->type != 2)
	  {
	    this->_x += x;    
	    _nodeAnim->setRotation(irr::core::vector3df(-90, 0, 0));
	    _nodeAnim->setPosition(irr::core::vector3df(this->_x, _y , 0));	    
	    if (_id_player == 1)
	      _nodeAnim->setMaterialTexture(0, driver->getTexture("imgs/Bomber.PCX"));
	    else
	      _nodeAnim->setMaterialTexture(0, driver->getTexture("imgs/Mexican.pcx"));
	    _nodeAnim->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	    _nodeAnim->setScale(irr::core::vector3df(0.025f, 0.025f, 0.025f));
	    _nodeAnim->setFrameLoop(400, 600);
	    _nodeAnim->setAnimationSpeed(30);
	  }
      }
    }
    else if (y > 0){
      if (_map[this->_x][(this->_y+y)+0.2] != NULL){
        if (_map[this->_x][(this->_y+y)+0.2]->type != 1 && _map[this->_x][(this->_y+y)+0.2]->type != 2)
	  {
	    this->_y += y;
	    _nodeAnim->setRotation(irr::core::vector3df(-90, 0, 90));
	    _nodeAnim->setPosition(irr::core::vector3df(_x, this->_y, 0));
	    if (_id_player == 1)
	      _nodeAnim->setMaterialTexture(0, driver->getTexture("imgs/Bomber.PCX"));
	    else
	      _nodeAnim->setMaterialTexture(0, driver->getTexture("imgs/Mexican.pcx"));
	    _nodeAnim->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	    _nodeAnim->setScale(irr::core::vector3df(0.025f, 0.025f, 0.025f));
	    _nodeAnim->setFrameLoop(400, 600);
	    _nodeAnim->setAnimationSpeed(30);
	  }
      }
    }
  }
  if (op == "-"){
    if (x > 0){
      if (_map[(this->_x-x)+0.2][this->_y] != NULL){
	if (_map[(this->_x-x)+0.2][this->_y]->type != 1 && _map[(this->_x-x)+0.2][this->_y]->type != 2)
	  {
	    this->_x -= x;
	    _nodeAnim->setRotation(irr::core::vector3df(-90, 0, 180));
	    _nodeAnim->setPosition(irr::core::vector3df(this->_x, _y , 0));
	    if (_id_player == 1)
	      _nodeAnim->setMaterialTexture(0, driver->getTexture("imgs/Bomber.PCX"));
	    else
	      _nodeAnim->setMaterialTexture(0, driver->getTexture("imgs/Mexican.pcx"));
	    _nodeAnim->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	    _nodeAnim->setScale(irr::core::vector3df(0.025f, 0.025f, 0.025f));
	    _nodeAnim->setFrameLoop(400, 600);
	    _nodeAnim->setAnimationSpeed(30);
	  }
      }
    }
    else if (y > 0){
      if (_map[this->_x][(this->_y-y)+0.2] != NULL){          
	if (_map[this->_x][(this->_y-y)+0.2]->type != 1 && _map[this->_x][(this->_y-y)+0.2]->type != 2)
	  {
	    this->_y -= y;
	    _nodeAnim->setRotation(irr::core::vector3df(-90, 0, -90));
	    _nodeAnim->setPosition(irr::core::vector3df(_x, this->_y, 0));
	    if (_id_player == 1)
	      _nodeAnim->setMaterialTexture(0, driver->getTexture("imgs/Bomber.PCX"));
	    else
	      _nodeAnim->setMaterialTexture(0, driver->getTexture("imgs/Mexican.pcx"));
	    _nodeAnim->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	    _nodeAnim->setScale(irr::core::vector3df(0.025f, 0.025f, 0.025f));
	    _nodeAnim->setFrameLoop(400, 600);
	    _nodeAnim->setAnimationSpeed(30);
	  }
      }
    }
  }
}

Player	&Player::operator=(Player const &old)
{
  _size_map = old._size_map;
  _map = old._map;
  _x = old._x;
  _y = old._y;
  _life = old._life;
  _nb_bombs = old._nb_bombs;
  _range = old._range;
  _speed = old._range;
  return  (*this);
}
