#include "SeaChecker.h"
#include "VertabrateCreature.h"
#ifndef VERT_CHECKER
#define VERT_CHECKER
class InvertabrateChecker: SeaChecker
{
  public:
  void SetMediator(Mediator *mediator);
  bool IsValid(VertabrateCreature *creature);
  protected:
  void* mediator;
};
#endif
