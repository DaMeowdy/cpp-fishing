#include <string>
#include "SeaCreature.h"
#ifndef MEDIATOR 
#define MEDIATOR
class Mediator 
{
  public:
  virtual void Notify(void* sender, std::string event_code, SeaCreature *object) =0;
};
#endif
