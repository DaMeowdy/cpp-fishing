#include "../include/VertabrateCreature.h"
VertabrateCreature::VertabrateCreature(std::string name, float size):_name{name}, _size{size}
{
}
std::string VertabrateCreature::getName() const{
  return this->_name;
}
float VertabrateCreature::getSize() const
{
  return this->_size;
};
std::string VertabrateCreature::toString() const
{
  return "";
};
