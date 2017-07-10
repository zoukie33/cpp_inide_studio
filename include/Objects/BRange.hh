//
// BRange.hh for BRange in /home/zoukie/Desktop/epitech/cpp_indie_studio/include/Objects
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Mon May 22 19:54:19 2017 
// Last update Wed Jun 21 08:26:01 2017 
//

#ifndef BRANGE_HH_
# define BRANGE_HH_

# include "Objects.hh"

class					BRange : public Objects
{

private:
  
  
public:

  BRange(float x, float y);
  ~BRange();

  virtual void				SetAff();

  irr::scene::IAnimatedMesh		*mesh;
  irr::scene::IAnimatedMeshSceneNode	*node;
  float					x;
  float					y;
  
};

#endif
