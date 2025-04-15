#include "../include/InvertabrateCreature.h"
InvertabrateCreature::InvertabrateCreature(std::string name, float size, bool carrying_eggs):_name{name},_size{size},_carryingEggs(carrying_eggs)
{
};
std::string InvertabrateCreature::getName() const
{
  return this->_name;
}
float InvertabrateCreature::getSize() const
{
  return this->_size;
}
std::string InvertabrateCreature::toString() const
{
  return "";
}
