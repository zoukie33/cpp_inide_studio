//
// main.cpp for main in /home/zoukie/Desktop/epitech/cpp_indie_studio
//
// Made by
// Login   <romain.gadrat@epitech.eu>
//
// Started on  Wed May 24 19:33:02 2017
// Last update Thu Jun 22 05:39:27 2017 
//

# include <list>
# include "irrlicht.h"
# include "IrrlichtDevice.h"
# include "irrKlang.h"
# include "Base.hh"
# include "Map.hh"
# include "Logs.hh"
# include "Player.hh"
# include "Save.hh"
# include "Game.hh"
# include "BBomb.hh"
# include "EventReceiver.hh"

# include <exception>

#pragma comment(lib, "irrKlang.lib")


#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

irr::video::IVideoDriver* driver;
irr::IrrlichtDevice* device;
irr::scene::ISceneManager* smgr;
Logs *logs  = new Logs();
std::list<BBomb*> Blist;


int     main()
{
  // SOUNDS

  irrklang::ISoundEngine* engine = irrklang::createIrrKlangDevice();  
     if (!engine)
      return 0;
  irrklang::ISound* snd = engine->play2D("media/bomberman_orchestra.ogg", true, false, true);
  snd->setVolume(0.2);  
  Game *g = new Game(1920, 1080);

  device = g->device;
  size_t	i;
  size_t	j;
  i = 0;
  j = 0;

  try {
    if (!g->device)
      return 1;
    g->device->setWindowCaption(L"Indie Studio - Bomberman");

    driver = g->device->getVideoDriver();
    smgr = g->device->getSceneManager();

    smgr->addCameraSceneNode(0, irr::core::vector3df(10,10,-21), irr::core::vector3df(10,10,21));

    /** DEBUT DES BOUTONS **/
    logs->Out("Main", "Initialisation des boutons.");


    EventReceiver receiver(*g->context);
    g->device->setEventReceiver(&receiver);
    g->context->popMenu();
    g->context->device = g->device;
    g->context->counter = 0;



    /***** FIN DES BOUTONS ****/


    g->CreateMap(20);


    /*** partie de maxence à revoir avec le load des data */
    logs->Out("Main", "Initialisation des Players.");
    
    Player p1(1, g->map, 1, 1);
    Player p2(2, g->map, 18, 18);

    logs->Out("Main", "Initialisation du device.");   
    g->map->fill_ground();
    while(g->device->run())
      {
  	driver->beginScene(true, true, irr::video::SColor(10,10,10,10));
  	smgr->drawAll();
  	if (receiver.launchGame == 1)
  	  {
	    std::list<Player> tab_player = {p1,p2};
	    g->map->fillMap();
  	  }
	if (receiver.IsKeyDown(irr::KEY_ESCAPE))
	    {
	      g->context->popMenu();
	        g->GamePaused = 1;
	    }
        if(receiver.IsKeyDown(irr::KEY_KEY_Z)){
          p1.SetPosition(0, 0.2, "+");
        }
        else if(receiver.IsKeyDown(irr::KEY_KEY_S)){
          p1.SetPosition(0, 0.2, "-");
        }
        if(receiver.IsKeyDown(irr::KEY_KEY_Q)){
          p1.SetPosition(0.2, 0, "-");
        }
        else if(receiver.IsKeyDown(irr::KEY_KEY_D)){
          p1.SetPosition(0.2, 0, "+");
        }
        else if (receiver.IsKeyDown(irr::KEY_SPACE)){
          p1.DropBomb();
        }

	if(receiver.IsKeyDown(irr::KEY_UP)){
          p2.SetPosition(0, 0.2, "+");
        }
        else if(receiver.IsKeyDown(irr::KEY_DOWN)){
          p2.SetPosition(0, 0.2, "-");
        }
        if(receiver.IsKeyDown(irr::KEY_LEFT)){
          p2.SetPosition(0.2, 0, "-");
        }
        else if(receiver.IsKeyDown(irr::KEY_RIGHT)){
          p2.SetPosition(0.2, 0, "+");
        }
        else if (receiver.IsKeyDown(irr::KEY_RSHIFT)){
          p2.DropBomb();
        }
	g->guienv->drawAll();
  	driver->endScene();
      }
    g->device->drop();
  }
  catch (std::exception *e)
    {
      std::cout << e->what() << std::endl;
    }
  logs->Out("Main", "Coupure du programme.");
  return 0;
}
