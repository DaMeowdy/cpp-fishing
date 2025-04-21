#include <string>
#include "SeaCreature.h"
#ifndef INVERTABRATE_CREATURE_HPP
#define INVERTABRATE_CREATURE_HPP
class InvertabrateCreature : public SeaCreature
{
  private:
  std::string _name{}; 
  float _size{};
  bool _carryingEggs{};
  public:
  InvertabrateCreature(std::string name, float size, bool carrying_eggs);
  std::string getName() const;
  float getSize() const;
  std::string toString() const;
};

#endif
