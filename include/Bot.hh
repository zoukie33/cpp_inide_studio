//
// Bot.hh for Bot hh in /home/zoukie/Desktop/epitech/cpp_indie_studio/include
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Mon Jun  5 17:24:48 2017 
// Last update Fri Jun  9 12:41:07 2017 maxence.lauque
//

# include "Map.hh"
# include "Characters.hh"

class Bot : public Characters
{

public:
  Bot(Map *map, int x, int y);
  ~Bot();
  virtual int	get_idPlayer() const;
  virtual void	set_idPlayer(int new_id);
  virtual int	get_x() const;
  virtual void	set_x(int new_x);
  virtual int	get_y() const;
  virtual void	set_y(int new_y);
  virtual int	get_speed() const;
  virtual void	set_speed(int new_speed);
  virtual int	get_range() const;
  virtual void	set_range(int new_range);
  virtual bool	get_life() const;
  virtual void	set_life(bool new_life);
  virtual int	get_nbBombs() const;
  virtual int	set_nbBombs(int new_nbBombs);
  virtual void	go_up();
  virtual void	go_down();
  virtual void	go_left();
  virtual void	go_right();
  virtual void	DropBomb();

private:

  int	_idPlayer;
  int	_x;
  int	_y;
  std::vector< std::vector< Objects *> >	map;
  int	_speed;
  int	_range;
  bool	_life;
  int	_nb_bombs;
  int	_bomb_used;
};
