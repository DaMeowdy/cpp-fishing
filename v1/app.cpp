#include "SeaPlusPlusEngine.cpp"
#include <iostream>

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
  private:
  int RunTimeLoop(bool isRunning);
  int TakeBeginningInput();
  int AddVertabrates();
  int AddInvertabrates();
};
#endif
int App::TakeBeginningInput()
{
  int choice;
  std::cout << "OPTIONS :" << std::endl << "1. Add Vertabrate"<<std::endl << "2. Add Invertabrate" << "3. Exit" <<std::endl<<"Enter Selection > ";
  std::cin >> choice;
  switch (choice)
  {
  case 1:
    return 1;
  case 2:
    return 2;
  case 3:
    return 0;
  default:
    std::cout << "Invalid Input" << choice << " ." << std::endl;
    this->TakeBeginningInput();
    break;
  }
  return 0;
}
int AddVertabrates()
{

}
int AddInvertabrates()
{

}
int App::RunTimeLoop(bool isRunning)
{
  if(!isRunning)
    return 0;
  int input = this->TakeBeginningInput();
  switch(input)
  {
    case 1:
      this->AddVertabrates();
      break;
    case 2:
      this->AddInvertabrates();
      break;
    case 0:
      isRunning = false;
      break;
  }
  this->RunTimeLoop(isRunning);
}
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
  std::cout << "WELCOME TO SEAPLUSPLUS" << std::endl << "セアプラスプラスへようくそ";
  RunTimeLoop(true);
}
void App::Cleanup()
{
  this->engine.CleanUp();
  this->sea_creature.CleanUp();
  this->invertabrate_checker.CleanUp();
  this->vertabrate_checker.CleanUp();
}
