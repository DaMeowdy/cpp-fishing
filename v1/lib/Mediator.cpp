#include "../include/Mediator.h"


void Mediator::Notify(void *sender, std::string event_code) const
{
  if(sender==this->_factory)
  {

  } else if (sender == this->app)
  {

  } else if (sender == this->checker)
  {
    
  }
};
void Mediator::SetFactory(SeaCreatureFactory* factory)
{
  this->_factory = factory;
}
