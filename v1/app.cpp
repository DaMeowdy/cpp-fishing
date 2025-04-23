#include "SeaPlusPlusEngine.cpp"

#ifndef APP
#define APP
class App
{
  public:
  App();
  void SetUp();
  void Run();
  void Cleanup();
  protected:
  SeaPlusPlusEngine engine;
  SeaCreature sea_creature;
  InvertabrateChecker invertabrate_checker;
  VertabrateChecker vertabrate_checker;
};
#endif

void App::SetUp()
{
  this->engine = SeaPlusPlusEngine();
  this->engine.SetUpCreature(&this->sea_creature);
  this->engine.SetUpInvertabrateChecker(&this->invertabrate_checker);
  this->engine.SetUpVertabrateChecker(&this->vertabrate_checker);
  this->sea_creature.SetMediator(&this->engine);
  this->invertabrate_checker.SetMediator(&this->engine);
  this->vertabrate_checker.SetMediator(&this->engine);
}
void App::Run()
{

}
void App::Cleanup()
{
  this->engine.CleanUp();
  this->sea_creature.CleanUp();
  this->invertabrate_checker.CleanUp();
  this->vertabrate_checker.CleanUp();
}
