#include <sstream>
#include <string>
#ifndef INVERTABRATE_CREATURE
#define INVERTABRATE_CREATURE
class InvertabrateCreature
{
  public:
  std::string name;
  float size;
  bool carrying_eggs;
  int qty;
  std::string ToFileString();
};
std::string InvertabrateCreature::ToFileString()
{
  std::stringstream ss;
  ss << this->name << "," << this->size << "," << this->qty << std::endl;
  return ss.str();
}
#endif
