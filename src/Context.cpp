//
// Context.cpp for  in /home/beche/cpp_indie_studio/src
// 
// Made by beche
// Login   <francois.beche@epitech.eu>
// 
// Started on  Mon Jun 12 20:49:19 2017 beche
// Last update Thu Jun 22 05:53:17 2017 
//

# include "irrlicht.h"
# include "IrrlichtDevice.h"

# include <iostream>
# include <string>
# include <stdlib.h>
# include <Context.hh>
# include <stdio.h>
# include <time.h>
# include <list>
# include "Base.hh"
# include "EventReceiver.hh"
# include "Context.hh"

SAppContext::SAppContext(irr::gui::IGUIEnvironment *guienv) :guienv(guienv)
{
  this->paused = 0;
}

SAppContext::~SAppContext()
{

}

void	SAppContext::popMenu()
{

  irr::gui::IGUIButton* b;
  if (paused == 0)
    this->img = this->guienv->addImage(driver->getTexture("./media/Background_opt2.png"), irr::core::position2d<int>(435,-75));
 
  b = this->guienv->addButton(irr::core::rect<irr::s32>(747, 600,1172,650 + 32), 0,
			      GUI_ID_PLAY_BUTTON,L"");
  this->menu.push_back(b);
  b->setImage(driver->getTexture("imgs/PLAY.png"));

    if (paused == 0)
      {
	b = this->guienv->addButton(irr::core::rect<irr::s32>(747, 700,1172,750 + 32), 0,
				    GUI_ID_CONFIG_BUTTON, L"");
	this->menu.push_back(b);
	b->setImage(driver->getTexture("imgs/OPTIONS.png"));
      }
    b =  this->guienv->addButton(irr::core::rect<irr::s32>(747,800,1172,850 + 32), 0,
				 GUI_ID_QUIT_BUTTON, L"");
  this->menu.push_back(b);
  b->setImage(driver->getTexture("imgs/EXIT.png"));
}

void	SAppContext::depopMenu()
{
  std::list<irr::gui::IGUIButton*>::iterator it;
  for(it = this->menu.begin(); it != this->menu.end(); it++)
    {
      irr::gui::IGUIButton *b;
      b = *it;
      b->remove();
    }  
  if (paused == 0)
    this->img->remove();
  this->menu.clear();
  paused = 1;
}
