//
// Empty.hh for EMPTY in /home/zoukie/Desktop/epitech/cpp_indie_studio/include/Objects
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Mon May 22 19:48:04 2017 
// Last update Thu Jun 22 04:42:58 2017 
//

#ifndef EMPTY_HH_
# define EMPTY_HH_

# include "Objects.hh"
# include "BBomb.hh"
// # include "Fire.hh"

# include <ctime>

//extern std::list<Fire*> Flist;

class				Empty : public Objects
{

private:

  
public:

  Objects			*_cont;

  Empty(float x, float y);
  ~Empty();

  virtual void			addObject(Objects *obj);
  Objects			*getCont() const;
  virtual void			update();
  float				x;
  float				y;
  int				_isFull;
};

#endif
