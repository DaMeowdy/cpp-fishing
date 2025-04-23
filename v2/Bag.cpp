#include "Mediator.cpp"
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#ifndef BAG
#define BAG
class Bag 
{
  public:
  std::vector<InvertabrateCreature> invertabrate_bag;
  std::vector<VertabrateCreature> vertabrate_bag; 
  void SetMediator(Mediator* Mediator);
  void ReadBag();
  void SaveBag();
  void AddInvertToBag(InvertabrateCreature* fish);
  void AddVertToBag(VertabrateCreature* fish);
  void PrintBag();
  void CleanUp();
  std::vector<std::string> SplitFileData(std::string& line);
  protected:
  Mediator* mediator;
};
#endif
std::vector<std::string> Bag::SplitFileData(std::string& line)
{
  std::vector<std::string> split_items;
  std::regex pattern("\\s*,\\s*");
  std::sregex_token_iterator begin(line.begin(),line.end(),pattern,-1);
  std::sregex_token_iterator end;
  for(std::sregex_token_iterator iterator = begin; iterator != end; ++iterator)
  {
    split_items.push_back(*iterator);
  }
  return split_items;
}
void Bag::SetMediator(Mediator* mediator)
{
  this->mediator = mediator;
};
void Bag::CleanUp()
{
  this->mediator = nullptr;
}
void Bag::PrintBag()
{
  std::cout << "INVERTABRATES"<<std::endl;
  for(auto& invertabrate: this->invertabrate_bag)
  {
    std::cout << invertabrate.ToFileString() << std::endl; 
  }
  std::cout << "VERTABRATES" <<std::endl;
  for(auto& vertabrate: this->invertabrate_bag)
  {
    std::cout << vertabrate.ToFileString() << std::endl; 
  }
}
void Bag::ReadBag()
{
  std::ifstream invertabrate_infile("INVERT_BAG_OUTPUT.txt");
  std::ifstream vertabrate_infile("VERTABRATE_BAG_OUTPUT.txt");
  std::string buffer;
  while(std::getline(invertabrate_infile, buffer))
  {
    std::vector<std::string> split = this->SplitFileData(buffer);
    InvertabrateCreature creature;
    creature.name= split.at(0);
    creature.size = std::stof(split.at(1));
    creature.qty = std::stoi(split.at(2));
    this->invertabrate_bag.push_back(creature);
  }
  while(std::getline(vertabrate_infile, buffer))
  {
    std::vector<std::string> split = this->SplitFileData(buffer);
    VertabrateCreature creature;
    creature.name= split.at(0);
    creature.size = std::stof(split.at(1));
    creature.qty = std::stoi(split.at(2));
    this->vertabrate_bag.push_back(creature);
  }
  vertabrate_infile.close();
  invertabrate_infile.close();

}
void Bag::SaveBag()
{
  std::ofstream invertabrate_outfile("INVERT_BAG_OUTPUT.txt");
  for(auto& fish:this->invertabrate_bag)
  {
    invertabrate_outfile << fish.ToFileString();
  }
  invertabrate_outfile.close();
  std::ofstream vertabrate_outfile("VERTABRATE_BAG_OUTPUT.txt");
  for(auto& fish:this->vertabrate_bag)
  {
    vertabrate_outfile << fish.ToFileString();
  }
  vertabrate_outfile.close();

}
void Bag::AddInvertToBag(InvertabrateCreature* fish)
{
  this->invertabrate_bag.push_back(*fish);
}
void Bag::AddVertToBag(VertabrateCreature* fish)
{
  this->vertabrate_bag.push_back(*fish);
}
