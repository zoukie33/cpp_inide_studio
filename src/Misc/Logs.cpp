//
// Logs.cpp for Logs in /home/zoukie/Desktop/epitech/cpp_indie_studio/src
// 
// Made by 
// Login   <romain.gadrat@epitech.eu>
// 
// Started on  Sun Jun 11 00:44:24 2017 
// Last update Sun Jun 11 15:59:42 2017 
//

# include "Logs.hh"

Logs::Logs()
{
  time_t	rawtime;
  struct	tm * timeinfo;
  char	buffer[80];
  time (&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(buffer, sizeof(buffer), "%d%m%Y%I%M%S", timeinfo);
  std::string date(buffer);
  _date = date;
  _file.open("Logs/logs" + _date + ".txt", std::ios::in | std::ios::trunc);
  _file << "Starting logs." << std::endl;
  std::cout << BOLD(FMAG("[LOGS]")) << FYEL(" - ") << FCYN("All logs will be saved in a file.") << std::endl;
}

Logs::~Logs()
{
  _file.close();
}

void	Logs::Out(std::string className, std::string message)
{
  this->_file << FMAG("[" << className << "]") << FYEL(" - ") << FCYN("" <<  message << "") << std::endl;
  std::cout << FMAG("[" << className << "]") << FYEL(" - ") << FCYN("" <<  message << "") << std::endl;
}

void	Logs::EOut(std::string className, std::string message)
{
  this->_file << BOLD(FRED("ERR : ")) << FMAG("[" << className << "]") << FYEL(" - " << message << "") << std::endl;
  std::cout << BOLD(FRED("ERR : ")) << FMAG("[" << className << "]") << FYEL(" - " << message << "") << std::endl;
}
