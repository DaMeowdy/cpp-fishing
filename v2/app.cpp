#include "SeaPlusPlusEngine.cpp"
#include <iostream>
#include <unordered_map>
#include <locale>
#ifndef APP
#define APP
class App
{
  public:
  void SetUp();
  void Run();
  void Cleanup();
  void ClearScreen();
  protected:
  SeaPlusPlusEngine engine;
  SeaCreature sea_creature;
  InvertabrateChecker invertabrate_checker;
  VertabrateChecker vertabrate_checker;
  Bag bag;
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
  this->bag.PrintBag();
  std::cout << std::endl;
  std::cout <<std::endl<< "OPTIONS :" << std::endl << "1. Add Vertabrate"<<std::endl << "2. Add Invertabrate" <<std::endl<< "3. Save Bag" << std::endl << "4. Load Bag" << std::endl << "5. Exit" <<std::endl<<"Enter Selection > ";
  std::cin >> choice;
  switch (choice)
  {
  case 1:
    return 1;
  case 2:
    return 2;
  case 3:
    return 3;
  case 4:
    return 4;
  case 5:
    return 0;
  default:
    std::cout << "Invalid Input" << choice << " ." << std::endl;
    this->TakeBeginningInput();
    break;
  }
  return 0;
}
int App::AddVertabrates()
{
  this->ClearScreen();
  std::unordered_map<std::string, std::vector<std::string>> map = this->vertabrate_checker.getSpecies();
  int choice;
  std::cout << "SELECT FROM FAMILIES : " <<std::endl;
  std::unordered_map<int, std::vector<std::string>> choices;
  int i = 1;
  for(auto& [key, value]:map)
  {
    choices[i] = value;
    std::cout << i << ". " << key << std::endl;
    ++i;
  }
  std::cout << "CHOOSE GROUP > ";
  std::cin >> choice;
  this->ClearScreen();
  int j = 1;
  std::vector<std::string> fish_of_group;
  for(auto& value:choices[choice])
  {
    fish_of_group.push_back(value);
    std::cout << j << ". " << value << std::endl;
    ++j;
  }
  std::cout << "CHOOSE FISH > ";
  std::cin >> choice;
  this->ClearScreen();
  std::string chosen_fish = fish_of_group.at(choice-1);
  int size; 
  int qty;
  std::cout << std::endl << "ENTER SIZE (in CM)> ";
  std::cin >> size;
  std::cout << std::endl << "ENTER QTY > ";
  std::cin >> qty;
  this->sea_creature.CreateVertabrateCreature(chosen_fish,size,qty);
  return choice;
}
int App::AddInvertabrates()
{
  this->ClearScreen();
  std::unordered_map<std::string, std::vector<std::string>> map = this->invertabrate_checker.getSpecies();
  int choice;
  std::cout << "SELECT FROM FAMILIES : " <<std::endl;
  std::unordered_map<int, std::vector<std::string>> choices;
  int i = 1;
  for(auto& [key, value]:map)
  {
    choices[i] = value;
    std::cout << i << ". " << key << std::endl;
    ++i;
  }
  std::cout << "CHOOSE GROUP > ";
  std::cin >> choice;
  this->ClearScreen();
  int j = 1;
  std::vector<std::string> fish_of_group;
  for(auto& value:choices[choice])
  {
    fish_of_group.push_back(value);
    std::cout << j << ". " << value << std::endl;
    ++j;
  }
  std::cout << "CHOOSE FISH > ";
  std::cin >> choice;
  this->ClearScreen();
  std::string chosen_fish = fish_of_group.at(choice-1);
  int size; 
  int qty;
  bool carrying_eggs;
  char yn;
  std::cout << std::endl << "ENTER SIZE (in CM)> ";
  std::cin >> size;
  std::cout << std::endl << "ENTER QTY > ";
  std::cin >> qty;
  std::cout << std::endl << "Is carrying eggs? y/n > ";
  std::cin >> yn;
  yn = tolower(yn);
  if(yn=='y')
  {
    carrying_eggs=true;
  }
  else if(yn=='n') {
    carrying_eggs=false;
  }
  this->sea_creature.CreateInvertabrateCreature(chosen_fish,size,carrying_eggs,qty);
  return choice;
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
    case 3:
      this->bag.SaveBag();
      this->ClearScreen();
      break;
    case 4:
      this->bag.ReadBag();
      this->ClearScreen();
      break;
    case 0:
      isRunning = false;
      break;
  }
  this->RunTimeLoop(isRunning);
  return 0;
}
void App::SetUp()
{
  this->engine = SeaPlusPlusEngine();
  this->engine.SetUpCreature(&this->sea_creature);
  this->engine.SetUpInvertabrateChecker(&this->invertabrate_checker);
  this->engine.SetUpVertabrateChecker(&this->vertabrate_checker);
  this->engine.SetUpBag(&this->bag);
  this->sea_creature.SetMediator(&this->engine);
  this->invertabrate_checker.SetMediator(&this->engine);
  this->vertabrate_checker.SetMediator(&this->engine);
  this->bag.SetMediator(&this->engine);
  this->bag.ReadBag();
}
void App::Run()
{
  std::string japanese =  "Seapurasupurasu e youkuso";
  std::cout << "WELCOME TO SEAPLUSPLUS" << std::endl;
  std::cout << japanese << std::endl;
  RunTimeLoop(true);
}
void App::ClearScreen()
{
  std::cout <<  "\033[2J\033[1;1H";
}
void App::Cleanup()
{
  this->engine.CleanUp();
  this->sea_creature.CleanUp();
  this->invertabrate_checker.CleanUp();
  this->vertabrate_checker.CleanUp();
}
