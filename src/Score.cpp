//
// Score.cpp for Project-Master in /home/vatout/epitech/cpp_indie_studio/src/Objects
// 
// Made by vatout_a
// Login   <artem.vatoutine@epitech.eu@epitech.eu>
// 
// Started on  Mon May 29 17:47:49 2017 vatout_a
// Last update Wed Jun 21 11:16:25 2017 
//

# include "Score.hh"
# inckude "Base.hh"

Score::Score(int idPlayer) : Player(idPlayer)
{
  _idPlayer = idPlayer;
  _score = 0;
}

Score::~Score()
{
}

void		Score::addScore(int score)
{
  logs-Out("Base", "Le joueur viens de gagner "+ score + " points");
  _score += score;
}

int		Score::getScore()
{
  return (_score);
}
