//
// map.cpp for map in /home/zoukie/epitech/cpp_indie_studio/src
// 
// Made by zoukie
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Wed May 10 14:37:14 2017 zoukie
// Last update Thu Jun 22 07:23:30 2017 
//

# include "Map.hh"
# include "Base.hh"

Map::Map(size_t taille) : _Map(taille)
{
  _taille = taille;
}

Map::~Map()
{

}

// Functions //

void					Map::GenerateMap()
{
  std::vector<std::string>		filelist;
  int					nbFiles;
  int					rnd;

  srand(time(NULL));
  filelist = GetMaps();
  nbFiles = filelist.size();
  rnd = rand() % nbFiles;
  logs->Out("Map", "Map : " + filelist[rnd]);
  SetObjects(filelist[rnd]);
}

std::vector<std::string>		Map::GetMaps()
{
  DIR					*dir;
  struct dirent				*edir;
  int					len;
  std::vector<std::string>		filelist;
  std::string				str;
  dir = opendir("maps");
  if (dir)
    while (edir = readdir(dir))
      {
	len = strlen(edir->d_name);
	if (edir->d_name[len - 4 ] == '.' &&
	    edir->d_name[len - 3 ] == 't' &&
	    edir->d_name[len - 2 ] == 'x' &&
	    edir->d_name[len - 1 ] == 't')
	  {
	    str.assign(edir->d_name, strlen(edir->d_name));
	    filelist.push_back(str);
	  }
      }
  closedir(dir);
  return (filelist);
}

void					Map::fill_ground()
{
  irr::scene::IAnimatedMesh		*mesh = smgr->getMesh("images/cube.obj");
  irr::scene::IAnimatedMeshSceneNode	*node  = smgr->addAnimatedMeshSceneNode(mesh, 0, -1,
										irr::core::vector3df(0, 0, 0),
										irr::core::vector3df(0, 0, 0),
										irr::core::vector3df(25.5f, 27, 0.2f));
  if (node)
    {
      node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      node->setMD2Animation(irr::scene::EMAT_STAND);
      node->setMaterialTexture( 0, driver->getTexture("images/grass.jpg") );
      node->setPosition(irr::core::vector3df(8.5f,-10,20));
    }
}

void					Map::fillMap()
{

  for (size_t i = 0; i <= _Map.size() - 1; ++i)
    {
      for (size_t j = 0; j < _Map.size(); ++j)
	{
	  _Map[i][j]->SetAff();
	  if (_Map[i][j]->type == 0)
	    _Map[i][j]->update();
	}
    }
}

void					Map::SetObjects(std::string theFile)
{
  std::ifstream				file("./maps/" + theFile);
  int					i;
  std::string				line;
  

  if (file)
    {
      i = 0;
      while (std::getline(file, line))
	{
	  std::vector<Objects*> row(this->_taille);
	  for (size_t j = 0; j < line.size(); ++j)
	    {
	      if (line.at(j) == '0')
	  	row[j] = new Empty(i, (int)j);
	      else if (line.at(j) == '1')
	        row[j] = new Wall(i, (int)j);
	      else if (line.at(j) == '2')
	        row[j] = new Breakable(i, (int)j);
	    }
	  this->_Map.at(i) = row;
	  i++;
	}
    }
  else
    logs->EOut("Map", "Ouverture du fichier: " + theFile);
}

// Getteurs //

size_t					Map::getTaille() const
{
  return (_taille);
}

std::vector< std::vector<Objects *> >	Map::getMap() const
{
  return (_Map);
}

// Setteurs //

void					Map::setTaille(size_t taille)
{
  _taille = taille;
}

void					Map::setMap(std::vector< std::vector<Objects *> > Map)
{
  _Map = Map;
}

Map&					Map::operator=(Map const &old)
{
  _taille = old._taille;
  _Map = old._Map;
  return (*this);
}
