//
// MVitesse.hh for MVitesse in /home/zoukie/Desktop/epitech/cpp_indie_studio/include/Objects
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Wed May 24 15:30:56 2017 
// Last update Wed Jun 21 08:27:19 2017 
//

#ifndef MVITESSE_HH_
# define MVITESSE_HH_

# include "irrlicht.h"
# include "IrrlichtDevice.h"
# include "Objects.hh"

class					MVitesse : public Objects
{

private:
  
  
public:

  MVitesse(float x, float y);
  ~MVitesse();

  virtual void				SetAff();

  irr::scene::IAnimatedMesh		*mesh;
  irr::scene::IAnimatedMeshSceneNode	*node;
  float					x;
  float					y;
  
};

#endif /* !MVITESSE_HH_ */
