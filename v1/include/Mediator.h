#include <string>
#include "SeaCreatureFactory.h"
#ifndef MEDIATOR 
#define MEDIATOR
class Mediator 
{
  void Notify(void* sender, std::string event_code) const;
  void SetFactory(SeaCreatureFactory* factory);
  private:
  SeaCreatureFactory* _factory;
  void* app;
  void* checker;

};
#endif
