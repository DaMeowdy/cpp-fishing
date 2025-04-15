#include <memory>
#include <string>
#include "Mediator.h"
#include "SeaCreatureFactory.h"
#ifndef SEA_PLUS_PLUS_ENGINE_H
#define SEA_PLUS_PLUS_ENGINE_H
class SeaPlusPlusEngine
{
  public: 
  SeaPlusPlusEngine();
  void set_mediator(Mediator* _mediator);

  private:
  std::unique_ptr<Mediator> _mediator;
  std::unique_ptr<SeaCreatureFactory> _factory;
  
};
#endif
