//
// Score.hh for Project-Master in /home/vatout/epitech/cpp_indie_studio/src/Objects
// 
// Made by vatout_a
// Login   <artem.vatoutine@epitech.eu@epitech.eu>
// 
// Started on  Mon May 29 17:49:35 2017 vatout_a
// Last update Thu Jun  8 11:20:31 2017 
//

#ifndef SCORE_HH_
# define SCORE_HH_

# include "Player.hh"

class		Score : public Player
{

private:

  int		_score;
  int		_idPlayer;

public:

  Score();
  ~Score();
  void		addScore(int);
  int		getScore(void);

};

#endif /* !SCORE_HH_ */
