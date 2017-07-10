
//
// EventReceiver.hh for  in /home/beche/cpp_indie_studio/include
// 
// Made by beche
// Login   <francois.beche@epitech.eu>
// 
// Started on  Wed Jun  7 16:11:14 2017 beche
// Last update Thu Jun 22 05:40:38 2017 
//

#ifndef EVENTRECEIVER_HH_
# define EVENTRECEIVER_HH_

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "Irrlicht.lib")
#endif

#include "irrlicht.h"
#include "IrrlichtDevice.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <list>

#include "Context.hh"


enum
  {
    GUI_ID_QUIT_BUTTON = 101,
    GUI_ID_PLAY_BUTTON,
    GUI_ID_CONFIG_BUTTON,
    GUI_ID_LOAD_BUTTON
  };

class					EventReceiver : public irr::IEventReceiver
{
public:
  EventReceiver(SAppContext &context);
  ~EventReceiver();
  
  virtual bool				OnEvent(const irr::SEvent& event);
  void					deleteAllButton();
  void					addAllButton();
  int					launchGame = 0;
  virtual bool				IsKeyDown(irr::EKEY_CODE keyCode) const;
private:
  SAppContext				&Context;
  bool					KeyIsDown[irr::KEY_KEY_CODES_COUNT];
};  
#endif
