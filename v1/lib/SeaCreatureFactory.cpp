#include "../include/SeaCreatureFactory.h"
#include <memory>
#include "SeaCreatureFactory.h"

SeaCreatureFactory::SeaCreatureFactory()
{

}
std::unique_ptr<InvertabrateCreature> SeaCreatureFactory::CreateInvertabrateCreature(std::string name, float size, bool carrying_eggs) const
{
  InvertabrateCreature creature_temp(name, size, carrying_eggs);
  std::unique_ptr<InvertabrateCreature> creature = std::make_unique<InvertabrateCreature>(creature_temp);
  this->_mediator->Notify(const_cast<SeaCreatureFactory*>(this), "INVERT", const_cast<InvertabrateCreature*>(creature.get()));
  return creature;
}

std::unique_ptr<VertabrateCreature> SeaCreatureFactory::CreateVertabrateCreature(std::string name, float size) const
{
  VertabrateCreature creature_temp(name, size);
  std::unique_ptr<VertabrateCreature> creature = std::make_unique<VertabrateCreature>(creature_temp);
  this->_mediator->Notify(const_cast<SeaCreatureFactory*>(this), "VERT", const_cast<VertabrateCreature*>(creature.get()));
  return creature;
}
void SeaCreatureFactory::SetMediator(Mediator *mediator)
{
  this ->_mediator = mediator;
}
