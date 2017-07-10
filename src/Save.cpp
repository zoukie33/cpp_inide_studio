//
// Save.cpp for Save in /home/oem/home/cpp_indie_studio/Maxence/src
// 
// Made by maxence.lauque
// Login   <lauque_m@epitech.net>
// 
// Started on  Thu Jun  1 16:41:20 2017 maxence.lauque
// Last update Wed Jun 21 12:01:06 2017 
//

# include "Save.hh"

Save::Save(Map *Map, std::list<Player> P)
{
  time_t	rawtime;
  struct	tm * timeinfo;
  char		buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(buffer, sizeof(buffer), "%d%m%Y%I%M%S", timeinfo);
  std::string	str(buffer);
  save_date = str;
  save_mapSize = Map->getTaille();
  save_map = Map->getMap();
}

Save::~Save()
{
}

void	Save::Save_game(Map *Map, std::list<Player> P)
{
  std::string	file_name = "Save/Player-"+ save_date +".txt";
  std::ofstream	file(file_name, std::ios::in | std::ios::trunc);

  if (file)
    {
      for(std::list<Player>::iterator it = P.begin(); it != P.end(); it++)
	{
	  save_IdPlayer = it->get_IdPlayer();
	  save_x = it->get_x();
	  save_y = it->get_y();
	  save_life = it->get_life();
	  save_nbBombs = it->get_nbBombs();
	  save_range = it->get_range();
	  save_speed = it->get_speed();
	  magic_nb = Calculate_magic_number();
	  file << magic_nb << std::endl;
	  for (size_t inc = 0; inc < save_mapSize - 1; ++inc)
	    {
	      for (size_t j = 0; j < save_mapSize - 1; ++j)
		file << save_map[inc][j]->type;
	      if (inc + 2 < save_mapSize)
		file << ';';
	    }
	  file << std::endl;
	}
      file << save_IdPlayer << ';' << save_x << ';' << save_y << ';' << save_range << ';' << save_nbBombs << ';' << save_speed << ';' << save_life << std::endl;
    }
  else
    logs->EOut("Save", "Impossible d'écrire les données du player dans le fichier : Save/Map" + save_date + ".txt.");
  file.close();
}

int	Save::Calculate_magic_number()
{
  int	nb;

  nb = save_x + save_y + save_range + save_nbBombs + save_speed + save_life;
  nb = nb + (';' * 6);
  for (size_t i = 0; i < save_mapSize - 1; ++i)
    {
      for (size_t j = 0; j < save_mapSize - 1; ++j)
	nb = nb + save_map[i][j]->type;
      nb = nb + ';';
    }
  return (nb);
}
