//
// BVitesse.cpp for BVitesse in /home/zoukie/Desktop/epitech/cpp_indie_studio/src/Objects
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Mon May 22 20:20:46 2017 
// Last update Wed Jun 21 10:34:53 2017 
//

# include "BVitesse.hh"
# include "Base.hh"

BVitesse::BVitesse(float height, float weidth) : Objects(height, weidth)
{
  type = 5;
  this->mesh = smgr->getMesh("images/cube.obj");
  this->node = smgr->addAnimatedMeshSceneNode( mesh );
  x = height;
  y = weidth;
}

BVitesse::~BVitesse()
{

}

void    BVitesse::SetAff()
{
  if (this->node)
    {
      this->node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      this->node->setMD2Animation(irr::scene::EMAT_STAND);
      this->node->setMaterialTexture( 0, driver->getTexture("images/Wood_wall.jpg") );
      this->node->setPosition(irr::core::vector3df(this->x - 0.5, this->y - 0.5, 0));
    }
}
