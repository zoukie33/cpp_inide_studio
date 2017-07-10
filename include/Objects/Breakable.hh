//
// breakable.hh for breakable in /home/zoukie/Desktop/epitech/cpp_indie_studio/include/objects
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Mon May 22 19:39:57 2017 
// Last update Wed Jun 21 15:55:19 2017 
//

#ifndef BREAKABLE_HH_
# define BREAKABLE_HH_

# include "Objects.hh"

class					Breakable : public Objects
{

private:
  
  
public:

  Breakable(float height, float weidth);
  ~Breakable();
  virtual void				UnSetAff();
  virtual void				SetAff();
  virtual void				SetBomb();

  irr::scene::IAnimatedMesh		*mesh;
  irr::scene::IAnimatedMeshSceneNode	*node;
  float					x;
  float					y;
};

#endif
