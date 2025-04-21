#ifndef SEACREATURE_FACTORY_H
#define SEACREATURE_FACTORY_H
#include <memory>
#include <string>
#include "InvertabrateCreature.h"
#include "VertabrateCreature.h"
#include "Mediator.h"

class SeaCreatureFactory
{
  private:
  Mediator *_mediator;
  public:
  SeaCreatureFactory();
  std::unique_ptr<InvertabrateCreature> CreateInvertabrateCreature(std::string name, float size, bool carrying_eggs) const;
  std::unique_ptr<VertabrateCreature> CreateVertabrateCreature(std::string name, float size) const;
  void SetMediator(Mediator *mediator);
};

#endif
