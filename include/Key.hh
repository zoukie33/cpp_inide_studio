//
// Key.hh for  in /home/bourre_a/Semestre_4/cpp/cpp_indie_studio/include
//
// Made by Bourreau Quentin
// Login   <quentin.bourreau@epitech.eu>
//
// Started on  Wed Jun 21 19:24:18 2017 Bourreau Quentin
// Last update Wed Jun 21 19:45:42 2017 Bourreau Quentin
//

#ifndef KEY_HH_
# define KEY_HH_

# include "irrlicht.h"
# include "IrrlichtDevice.h"

typedef struct	s_key_player
{
  EKEY_CODE	up;
  EKEY_CODE	down;
  EKEY_CODE	left;
  EKEY_CODE	right;
  EKEY_CODE	bomb;
}	t_key_player;

#endif
