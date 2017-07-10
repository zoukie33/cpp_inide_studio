//
// wall.hh for WALL in /home/zoukie/Desktop/epitech/cpp_indie_studio/include/objects
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Mon May 22 19:43:45 2017 
// Last update Wed Jun 21 08:29:09 2017 
//

#ifndef WALL_HH_
# define WALL_HH_

# include "Objects.hh"

class					Wall : public Objects
{

private:
  
  
public:

  Wall(float height, float weidth);
  ~Wall();
  virtual void				SetAff();

  irr::scene::IAnimatedMesh		*mesh;
  irr::scene::IAnimatedMeshSceneNode	*node;
  float					x;
  float					y;
};

#endif /* !WALL_HH_ */
