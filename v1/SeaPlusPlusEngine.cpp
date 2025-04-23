#include "SeaCreature.cpp"
#include "Mediator.cpp"
#include "InvertabrateChecker.cpp"
#include "VertabrateChecker.cpp"
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
  void SetUpVertabrateChecker(VertabrateChecker* vertabrate_checker);
  void CleanUp();
  protected:
  SeaCreature* creature;
  InvertabrateChecker* invertabrate_checker;
  VertabrateChecker* vertabrate_checker;
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
void SeaPlusPlusEngine::SetUpVertabrateChecker(VertabrateChecker* vertabrate_checker)
{
  this->vertabrate_checker = vertabrate_checker;
  this->vertabrate_checker->LoadRules();
}
void SeaPlusPlusEngine::CleanUp()
{
  delete this->creature;
  delete this->invertabrate_checker;
  delete this->vertabrate_checker;
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
        //Logic for bag
      }
      else {
        // Logic for bag
      }
    }
  }
  if(sender==this->invertabrate_checker)
  {
    if(message=="VALID")
    {
      std::cout << "KEEP";
    }
    else if(message=="INVALID::NF")
    {
      std::cout << "RELEASE";
    }
    else if(message == "INVALID::SIZE")
    {
      std::cout << "RELEASE";
    }
    else if(message=="INVALID::QTY")
    {
      std::cout << "RELEASE";
    }
    else if(message=="INVALID::EGGS")
    {
      std::cout << "RELEASE";
    }
    else
    {
      std::cout << "RELEASE";
    }
  }
}
void SeaPlusPlusEngine::NotifyVertabrate(void* sender, std::string message, VertabrateCreature* object)
{
  if(sender==this->creature)
  {
    if(message=="CREATED")
    {
      bool is_valid = this->vertabrate_checker->CheckVertabrateCreature(object);
      if(is_valid)
      {
        //Logic for bag
      }
      else {
        // Logic for bag
      }
    }
  }
  if(sender==this->vertabrate_checker)
  {
    if(message=="VALID")
    {
      std::cout << "KEEP";
    }
    else if(message=="INVALID::NF")
    {
      std::cout << "RELEASE";
    }
    else if(message == "INVALID::SIZE")
    {
      std::cout << "RELEASE";
    }
    else if(message=="INVALID::QTY")
    {
      std::cout << "RELEASE";
    }
    else
    {
      std::cout << "RELEASE";
    }
  }
}
