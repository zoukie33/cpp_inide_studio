//
// Logs.hh for Logs in /home/zoukie/Desktop/epitech/cpp_indie_studio/include
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Sun Jun 11 00:44:43 2017 
// Last update Sun Jun 11 15:56:18 2017 
//

#ifndef LOGS_HH_
# define LOGS_HH_

# include "Colors.hh"
# include <string>
# include <iostream>
# include <fstream>
# include "time.h"
# include <stdio.h>
# include <stdlib.h>

class	Logs
{

public:

  Logs();
  ~Logs();

  void	Out(std::string className, std::string message);
  void	EOut(std::string className, std::string message);

private:

  std::ofstream	_file;
  std::string	_date;
  
};

#endif /* !LOGS_HH_ */
