#include "SeaCreature.cpp"
#include "Mediator.cpp"
#include "InvertabrateChecker.cpp"
#include <iostream>
#ifndef ENGINE
#define ENGINE

class SeaPlusPlusEngine: public Mediator
{
  public:
  void NotifyInvertabrate(void* sender, std::string message, InvertabrateCreature* object) override;
  void NotifyVertabrate(void* sender, std::string message, VertabrateCreature* object) override;
  void SetUpCreature(SeaCreature* creature);
  void SetUpInvertabrateChecker(InvertabrateChecker* invertabrate_checker);
  void CleanUp();
  protected:
  SeaCreature* creature;
  InvertabrateChecker* invertabrate_checker;
};
#endif
void SeaPlusPlusEngine::SetUpCreature(SeaCreature* creature)
{
  this->creature = creature;
}
void SeaPlusPlusEngine::SetUpInvertabrateChecker(InvertabrateChecker* invertabrate_checker)
{
  this->invertabrate_checker = invertabrate_checker;
  this->invertabrate_checker->LoadRules();
}
void SeaPlusPlusEngine::CleanUp()
{
  delete this->creature;
  delete this->invertabrate_checker;
}
void SeaPlusPlusEngine::NotifyInvertabrate(void* sender, std::string message, InvertabrateCreature* object) 
{
  if(sender==this->creature)
  {
    if(message=="CREATED")
    {
      bool is_valid = this->invertabrate_checker->CheckInvertabrateCreature(object);
      if(is_valid)
      {
        std::cout << "CREATURE VALID"; 
      }
      else {
        std::cout << "CREATURE INVALID";
      }
    }
  }
  if(sender==this->invertabrate_checker)
  {
    if(message=="VALID")
    {

    }
    else if(message=="INVALID::NF")
    {

    }
    else if(message == "INVALID::SIZE")
    {

    }
    else if(message=="INVALID::QTY")
    {

    }
    else if(message=="INVALID::EGGS")
    {

    }
    else
    {
      
    }
  }
}
void SeaPlusPlusEngine::NotifyVertabrate(void* sender, std::string message, VertabrateCreature* object)
{
  if(sender==this->creature)
  {
    if(message=="CREATED")
    {
      // run checker
    }
  }

}
