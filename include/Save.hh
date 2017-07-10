//
// Save.hh for save in /home/oem/home/cpp_indie_studio/Maxence/includes
// 
// Made by maxence.lauque
// Login   <lauque_m@epitech.net>
// 
// Started on  Thu Jun  1 16:43:25 2017 maxence.lauque
// Last update Mon Jun 12 18:24:30 2017 maxence.lauque
//

#ifndef SAVE_HH_
# define SAVE_HH_

# include <vector>
# include <fstream>
# include <iostream>
# include <string>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <list>
# include "Objects.hh"
# include "Map.hh"
# include "Player.hh"
# include "Base.hh"

class	Save
{

public:

  Save(Map *map, std::list<Player> player);
  ~Save();
  int	Calculate_magic_number();
  void	Save_game(Map *map, std::list<Player> P);

private:

  std::vector< std::vector<Objects *> > save_map;
  std::string	save_date;
  int	save_mapSize;
  int	magic_nb;
  int	save_IdPlayer;
  int	save_x;
  int	save_y;
  int	save_life;
  int	save_nbBombs;
  int	save_range;
  int	save_speed;

};

#endif /* !SAVE_HH_ */
