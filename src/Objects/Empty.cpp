//
// Empty.cpp for Empty in /home/zoukie/Desktop/epitech/cpp_indie_studio/src/Objects
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Mon May 22 20:21:31 2017 
// Last update Thu Jun 22 05:00:41 2017 
//

# include "Empty.hh"

Empty::Empty(float height, float weidth) : Objects(height, weidth)
{
  type = 0;
  x = height;
  y = weidth;
  _cont = NULL;
  _isFull = 0;
}

Empty::~Empty()
{

}


void	Empty::addObject(Objects *obj)
{
  logs->Out("Empty", "Adding bomb to empty");
  _cont = obj;
  _isFull = 1;
}


Objects	*Empty::getCont() const
{
  return (_cont);
}

void	Empty::update()
{
  if (_isFull == 1)
    {
      if (_cont->Explode())
	{
	  std::list<BBomb*>::iterator it;
	  for (it = Blist.begin(); it != Blist.end(); it++)
	    {
	      BBomb *i;

	      i = *it;
	      i->UnSetAff();	      
	    }
	  Blist.clear();
	  logs->Out("Empty", "Deleting _cont bomb");
	  delete _cont;
	  _cont = NULL;
	  _isFull = 0;
	}
      
    }
}
  
