#include <sstream>
#include <string>
#ifndef VERTABRATE_CREATURE
#define VERTABRATE_CREATURE
class VertabrateCreature
{
  public:
  std::string name;
  float size;
  int qty;
  std::string ToFileString();
};
std::string VertabrateCreature::ToFileString()
{
  std::stringstream ss;
  ss << this->name << "," << this->size << "," << this->qty << std::endl;
  return ss.str();
}
#endif
