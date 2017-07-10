//
// Context.hh for  in /home/beche/cpp_indie_studio/include
// 
// Made by beche
// Login   <francois.beche@epitech.eu>
// 
// Started on  Mon Jun 12 20:42:23 2017 beche
// Last update Thu Jun 22 05:46:23 2017 
//

#ifndef CONTEXT_HH_
# define CONTEXT_HH_

# include "irrlicht.h"
# include "IrrlichtDevice.h"

# include <iostream>
# include <string>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <list>

class							SAppContext
{

public:
  SAppContext(irr::gui::IGUIEnvironment			*guienv);
  ~SAppContext();
  void							popMenu();
  void							depopMenu();
  void	createOneButton(std::string name, int id, irr::core::rect<irr::s32> rec);
  irr::IrrlichtDevice					*device;
  irr::s32						counter;
  irr::gui::IGUIListBox*				listbox;
  irr::gui::IGUIEnvironment			        *guienv;
  std::list<irr::gui::IGUIButton*>			menu;
  void							setImg(int id, std::string path);
  irr::gui::IGUIImage					*img;
  int							paused;
};  
#endif /* !PLAYER_HH_ */
