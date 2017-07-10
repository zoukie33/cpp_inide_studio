//
// Bot.cpp for Bot in /home/zoukie/Desktop/epitech/cpp_indie_studio/src
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Tue Jun  6 17:12:07 2017 
// Last update Sun Jun 11 16:25:53 2017 
//

# include "Bot.hh"

Bot::Bot(int idPlayer, Map *map, int x, int y) : _life(true), _nb_bombs(1), _range(2), _speed(1)
{
  _idPlayer = idPlayer;
  _map = map->getMap();
  _x = x;
  _y = y;
  _bomb_used = 0;
}

Bot::~Bot()
{

}

int	Bot::get_idPlayer() const
{
  return (_idPlayer);
}

void	Bot::set_idPlayer(int new_id)
{
  _id_player = new_id;
}

int	Bot::get_x() const
{
  return (_x);
}

void	Bot::set_x(int new_x)
{
  _x = new_x;
}

int	Bot::get_y() const
{
  return (_y);
}


void	Bot::set_y(int new_y)
{
  _y = new_y;
}

int	Bot::get_speed() const
{
  return (_speed);
}

void	Bot::set_speed(int new_speed)
{
  _speed = new_speed;
}

int	Bot::get_range() const
{
  return (_range);
}


void	Bot::set_range(int new_range)
{
  _range = new_range;
}

int	Bot::get_life() const
{
  return (_life);
}


void	Bot::set_life(bool new_life)
{
  _life = new_life;
}

int	Bot::get_nbBombs() const
{
  return (_nb_bombs);
}


void	Bot::set_nbBombs(int new_nbBombs)
{
  _nbBombs = new_nbBombs;
}

void    Bot::go_down()
{
  if (_map[_x][_y++]->type != 1 &&
      _map[_x][_y++]->type != 2)
    {
      _y++;
      if (_map[_x][_y]->type == 3)
        _nb_bombs++;
      else if (_map[x][y]->type == 4)
        _range++;
      else if (_map[_x][_y]->type == 5)
	_speed++;
      else if (_map[_x][_y]->type == 6)
        _speed--;
    }
}

void    Bot::go_up()
{
  if (_map[_x][_y--]->type != 1 &&
      _map[_x][_y--]->type != 2)
    {
      _y--;
      if (_map[_x][_y]->type == 3)
        _nb_bombs++;
      else if (_map[_x][_y]->type == 4)
        _range++;
      else if (_map[_x][_y]->type == 5)
	_speed++;
      else if (_map[_x][_y]->type == 6)
        _speed--;
    }
}

void    Bot::go_left()
{
  if (_map[_x--][_y]->type != 1 &&
      _map[_x--][_y]->type != 2)
    {
      _x--;
      if (_map[_x][_y]->type == 3)
	_nb_bombs++;
      else if (_map[_x][_y]->type == 4)
	_range++;
      else if (_map[_x][_y]->type == 5)
	_speed++;
      else if (_map[_x][_y]->type == 6)
	_speed--;
    }
}

void    Bot::go_right()
{
  if (_map[_x++][_y]->type != 1 &&
      _map[_x++][_y]->type != 2)
    {
      _x++;
      if (_map[_x][_y]->type == 3)
	_nb_bombs++;
      else if (_map[_x][_y]->type == 4)
	_range++;
      else if (_map[_x][_y]->type == 5)
	_speed++;
      else if (_map[_x][_y]->type == 6)
	_speed--;
    }
}

void	Bot::DropBomb()
{
  if (_bomb_used < _nb_bombs)
    if (_map[_x][_y]->type == 0)
      {
	logs->Out("Bot", "A bot just dropped a Bomb.");
	_map[_x][_y]->addObject(new BBomb(_range, _idPlayer, _x, _y));
	_bomb_used++;
      }
}
