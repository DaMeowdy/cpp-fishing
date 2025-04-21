#include "SeaChecker.h"
#include "InvertabrateCreature.h"
#include <unordered_map>
#include "InvertabrateRules.h"
#ifndef INVERT_CHECKER
#define INVERT_CHECKER
class InvertabrateChecker: SeaChecker
{
  public:
  void SetMediator(Mediator *mediator);
  bool IsValid(InvertabrateCreature *creature);
  void AddRules();
  protected:
  void* mediator;
  std::unordered_map<std::string, InvertabrateRules> rules; 
};
#endif
