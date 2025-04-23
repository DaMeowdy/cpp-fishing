#include "Mediator.cpp"
#include "InvertabrateCreature.cpp"
#include "VertabrateCreature.cpp"
#include <iostream>
#ifndef SEA_CREATURE
#define SEA_CREATURE
class SeaCreature 
{
  public: 
  SeaCreature();
  void CleanUp();
  VertabrateCreature* CreateVertabrateCreature(std::string name, float size, int qty);
  InvertabrateCreature* CreateInvertabrateCreature(std::string name, float size, bool carrying_eggs, int qty);
  void SetMediator(Mediator* mediator);
  protected:
  Mediator* mediator;

};
#endif
void SeaCreature::SetMediator(Mediator* mediator)
{
  this->mediator=mediator;
}
SeaCreature::SeaCreature()
{
  this->mediator = nullptr;
}
void SeaCreature::CleanUp()
{
  this->mediator = nullptr;
}
InvertabrateCreature* SeaCreature::CreateInvertabrateCreature(std::string name, float size, bool carrying_eggs, int qty)
{
  if(!carrying_eggs)
  {
    carrying_eggs=false;
  }
  InvertabrateCreature creature;
  creature.name = name; 
  creature.size = size;
  creature.carrying_eggs = carrying_eggs;
  creature.qty = qty;
  if(this->mediator==nullptr)
  {
    return nullptr;
  }
  
  this->mediator->NotifyInvertabrate(this, "CREATED", &creature);
  return std::move(&creature);
}
VertabrateCreature* SeaCreature::CreateVertabrateCreature(std::string name, float size, int qty)
{
  VertabrateCreature creature;
  creature.name = name;
  creature.size = size;
  creature.qty = qty;
  if(this->mediator==nullptr)
  {
    return nullptr;
  }
  
  this->mediator->NotifyVertabrate(this, "CREATED", &creature);
  return std::move(&creature);
}
