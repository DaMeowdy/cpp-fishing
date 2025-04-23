#include "InvertabrateCreature.cpp"
#include "VertabrateCreature.cpp"
#include <string>
#ifndef MEDIATOR
#define MEDIATOR
class Mediator 
{
  public:
  virtual void NotifyInvertabrate(void* sender, std::string message, InvertabrateCreature* object) = 0;
  virtual void NotifyVertabrate(void* sender, std::string message, VertabrateCreature* object) = 0;
};
#endif
