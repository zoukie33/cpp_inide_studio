//
// EventReceiver.cpp for  in /home/beche/cpp_indie_studio/src
// 
// Made by beche
// Login   <francois.beche@epitech.eu>
// 
// Started on  Wed Jun  7 16:20:21 2017 beche
// Last update Thu Jun 22 05:43:31 2017 
//

# include "irrlicht.h"
# include "IrrlichtDevice.h"

#include "EventReceiver.hh"
#include "Game.hh"
#include "Context.hh"

EventReceiver::EventReceiver(SAppContext &context) : Context(context) {
  this->launchGame = 0;
  for (irr::u32 i=0; i < irr::KEY_KEY_CODES_COUNT; ++i)
      KeyIsDown[i] = false;
}

EventReceiver::~EventReceiver() { }

bool	EventReceiver::OnEvent(const irr::SEvent &event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT)
    KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
  if (event.EventType == irr::EET_GUI_EVENT)
    {
      irr::s32 id = event.GUIEvent.Caller->getID();
      irr::gui::IGUIEnvironment* env = Context.device->getGUIEnvironment();
      
      switch(event.GUIEvent.EventType)
	{
	case irr::gui::EGET_BUTTON_CLICKED:
	  switch(id)
	    {
	    case GUI_ID_QUIT_BUTTON:
	      Context.device->closeDevice();
	      std::cout << "On quitte " << std::endl;
	      return true;
	    case GUI_ID_PLAY_BUTTON:
	      std::cout << "GO TO PLAY" << std::endl;
	      this->launchGame = 1;
	      this->Context.depopMenu();
	    default:
	      return false;
	    }
	  break;
	case irr::gui::EGET_FILE_SELECTED:
	  {
	    // show the model filename, selected in the file dialog
	    irr::gui::IGUIFileOpenDialog* dialog =
	      (irr::gui::IGUIFileOpenDialog*)event.GUIEvent.Caller;
	    Context.listbox->addItem(dialog->getFileName());
	  }
	  break;
	default:
	  break;
	}
    }
  return false;
}

void    EventReceiver::deleteAllButton()
{
}

bool EventReceiver::IsKeyDown(irr::EKEY_CODE keyCode) const
{
  return KeyIsDown[keyCode];
}
