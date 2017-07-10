//
// BBomb.hh for BBomb in /home/zoukie/Desktop/epitech/cpp_indie_studio/include/Objects
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Mon May 22 19:53:27 2017 
// Last update Thu Jun 22 05:01:07 2017 
//

#ifndef BBOMB_HH_
# define BBOMB_HH_

# include "irrlicht.h"
# include "IrrlichtDevice.h"
# include "irrKlang.h"
# include "Objects.hh"
# include "Base.hh"
# include "Map.hh"
// # include "Fire.hh"

class		BBomb : public Objects
{

private:
  int							_range;
  int							_idPlayer;
  std::vector< std::vector< Objects *> >		_map;
  irr::u32						_startTime;

public:

  BBomb(int range, int player, float x, float y, std::vector< std::vector< Objects *> > map);
  ~BBomb();

  virtual void						SetAff();
  virtual void						UnSetAff();
  virtual int						Explode();
  void							DeleteCube(int x, int y);
  irr::scene::IAnimatedMesh				*mesh;
  irr::scene::IAnimatedMeshSceneNode			*nodeBomb;
  int							x;
  int							y;
};

extern std::list<BBomb*> Blist;

#endif /* !BBOMB_HH_ */
