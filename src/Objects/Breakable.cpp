//
// Breakable.cpp for Breakable in /home/zoukie/Desktop/epitech/cpp_indie_studio/src/Objects
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Mon May 22 20:19:46 2017 
// Last update Wed Jun 21 22:16:48 2017 
//

#include "Breakable.hh"
#include "Base.hh"

Breakable::Breakable(float height, float weidth) : Objects(height, weidth)
{
  type = 2;
  this->mesh = smgr->getMesh("images/cube.obj");
  this->node = smgr->addAnimatedMeshSceneNode( mesh, 0, -1,
					       irr::core::vector3df(0, 0, 0),
					       irr::core::vector3df(0, 0, 0),
					       irr::core::vector3df(0.705, 0.705, 0.705));
  this->x = height;
  this->y = weidth;
}

Breakable::~Breakable()
{
}

void  Breakable::SetAff()
{
  if (this->node)
    {
      this->node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      this->node->setMD2Animation(irr::scene::EMAT_STAND);
      this->node->setMaterialTexture( 0, driver->getTexture("images/Wood_wall.jpg") );
      this->node->setPosition(irr::core::vector3df(this->x, this->y, 0));
    }
}

void  Breakable::UnSetAff()
{
  if (node)
    node->remove();
}
void  Breakable::SetBomb(){}
