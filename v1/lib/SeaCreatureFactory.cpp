#include "../include/SeaCreatureFactory.h"
#include <memory>

SeaCreatureFactory::SeaCreatureFactory()
{

}
std::unique_ptr<InvertabrateCreature> SeaCreatureFactory::CreateInvertabrateCreature(std::string name, float size, bool carrying_eggs) const
{
  InvertabrateCreature creature_temp(name, size, carrying_eggs);
  std::unique_ptr<InvertabrateCreature> creature = std::make_unique<InvertabrateCreature>(creature_temp);
  return creature;
}

std::unique_ptr<VertabrateCreature> SeaCreatureFactory::CreateVertabrateCreature(std::string name, float size) const
{
  VertabrateCreature creature_temp(name, size);
  std::unique_ptr<VertabrateCreature> creature = std::make_unique<VertabrateCreature>(creature_temp);
  return creature;
}
