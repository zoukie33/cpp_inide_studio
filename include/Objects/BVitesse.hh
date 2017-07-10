//
// BVitesse.hh for BVitesse in /home/zoukie/Desktop/epitech/cpp_indie_studio/include/Objects
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Mon May 22 19:56:58 2017 
// Last update Wed Jun 21 08:25:41 2017 
//

#ifndef BVITESSE_HH_
# define BVITESSE_HH_

# include "irrlicht.h"
# include "IrrlichtDevice.h"
# include "Objects.hh"

class					BVitesse : public Objects
{

private:
  
  
public:

  BVitesse(float x, float y);
  ~BVitesse();

  virtual void				SetAff();

  irr::scene::IAnimatedMesh		*mesh;
  irr::scene::IAnimatedMeshSceneNode	*node;
  float					x;
  float					y;
  
};

#endif /* !BVITESSE_HH_ */
