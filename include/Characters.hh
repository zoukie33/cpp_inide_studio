/*
** attributes_char.h for attribute in /home/oem/home/cpp_indie_studio/Maxence
** 
** Made by maxence.lauque
** Login   <lauque_m@epitech.net>
** 
** Started on  Mon May 29 16:10:24 2017 maxence.lauque
// Last update Wed Jun 21 12:24:07 2017 maxence.lauque
*/

#ifndef CHARACTERS_HH_
# define CHARACTERS_HH_

# include "Objects.hh"
# include "Map.hh"

# include <iostream>
# include <string>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>


class	Characters
{
public:
  Characters(){}
  virtual ~Characters(){}
  virtual void	DropBomb() = 0;
  virtual int	get_IdPlayer()const = 0;
  virtual void	set_IdPlayer(int id_player) = 0;
  virtual float	get_x()const = 0;
  virtual void	set_x(float x) = 0;
  virtual float	get_y()const = 0;
  virtual void	set_y(float y) = 0;
  virtual bool	get_life()const = 0;
  virtual void	set_life(bool life) = 0;
  virtual int	get_nbBombs()const = 0;
  virtual void	set_nbBombs(int nb_boms) = 0;
  virtual int	get_range()const = 0;
  virtual void	set_range(int range) = 0;
  virtual int	get_speed()const = 0;
  virtual void	set_speed(int speed) = 0;
  Characters	&operator=(Characters const &old);
};

#endif /* !CHARACTERS_HH_ */
