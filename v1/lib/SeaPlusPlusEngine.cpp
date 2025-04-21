#include "../include/Mediator.h"
#include "../include/SeaCreatureFactory.h"
#include "../include/SeaChecker.h"
#include "../include/InvertabrateChecker.h"
class SeaPlusPlusEngine: public Mediator
{
  public:
  void Notify(void *sender, std::string event_code, SeaCreature *object) override
  {
    if(sender == this->factory)
    {
      if(event_code=="INVERT")
      {
        if(this->invertChecker->IsValid(object))
        {

        }
      }
    }
  }
  void SetFactory(SeaCreatureFactory *factory)
  {
    this->factory = factory;
  }
  void SetInvertabrateChecker(InvertabrateChecker *checker )
  {
    this->invertChecker = checker;
  }
  protected:
  SeaCreatureFactory *factory;
  InvertabrateChecker *invertChecker;

};
