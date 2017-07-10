//
// objects.hh for objects in /home/zoukie/epitech/cpp_indie_studio/include
// 
// Made by zoukie
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Wed May 10 14:43:51 2017 zoukie
// Last update Thu Jun 22 00:30:39 2017 
//

#ifndef OBJECTS_HH_
# define OBJECTS_HH_

# include "irrlicht.h"
# include "IrrlichtDevice.h"
# include "Base.hh"

class					Objects
{

private:

public:
  Objects				*_cont;
  Objects(float x, float y);
  ~Objects();
  int					type;

  irr::scene::ISceneManager*		_smgr;
  irr::scene::IAnimatedMeshSceneNode	*node;
  virtual void				SetAff();
  virtual void				UnSetAff();
  virtual void				addObject(Objects *obj);
  virtual int				Explode();
  virtual void				update();  
  float					x;
  float					y;
  int					_isFull;
};
#endif
