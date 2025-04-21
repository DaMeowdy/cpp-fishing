#ifndef VERTABRATECREATURE_H
#define VERTABRATECREATURE_H
#include <string>
#include "SeaCreature.h"
class VertabrateCreature: public SeaCreature
{
  protected:
  // add mediator here

  private:
  std::string _name{}; 
  float _size{};
  public:
  VertabrateCreature(std::string name, float size);
  std::string getName() const;
  float getSize() const;
  std::string toString() const;
  void setMediator(/*MEDIATOR CLASS*/) const;
};
#endif
