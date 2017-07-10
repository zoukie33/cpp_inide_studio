//
// BRange.cpp for BRange in /home/zoukie/Desktop/epitech/cpp_indie_studio/src/Objects
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Mon May 22 20:18:55 2017 
// Last update Wed Jun 21 10:33:58 2017 
//

# include "BRange.hh"
# include "Base.hh"

BRange::BRange(float height, float weidth) : Objects(height, weidth)
{
  type = 4;
  x = height;
  y = weidth;
}

BRange::~BRange()
{

}

void    BRange::SetAff()
{
  if (this->node)
    {
      this->node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      this->node->setMD2Animation(irr::scene::EMAT_STAND);
      this->node->setMaterialTexture( 0, driver->getTexture("images/Wood_wall.jpg"));
      this->node->setPosition(irr::core::vector3df(this->x - 0.5, this->y - 0.5, 0));
    }
}
