#include "SeaChecker.cpp"
#include "InvertabrateCreature.cpp"
#include "Mediator.cpp"
#include <fstream>
#include <regex>
#include <iostream>
#ifndef INVERTABRATE_CHECKER
#define INVERTABRATE_CHECKER
class InvertabrateChecker: public SeaChecker
{
  public:
  void LoadRules() override;
  void CleanUp() override;
  std::unordered_map<std::string, std::vector<std::string>> getSpecies();
  void SetMediator(Mediator* mediator);
  bool CheckInvertabrateCreature(InvertabrateCreature* creature);

  protected:
  Mediator* mediator;
  std::vector<std::string> SplitFileData(std::string& line);
};
std::vector<std::string> InvertabrateChecker::SplitFileData(std::string& line)
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
bool InvertabrateChecker::CheckInvertabrateCreature(InvertabrateCreature* creature)
{
  if(creature->carrying_eggs==true)
  {
    std::cout << creature->carrying_eggs;
    this->mediator->NotifyInvertabrate(this,"INVALID::EGGS",nullptr);
    return false;
  }
  if(this->rules.find(creature->name)==this->rules.end())
  {
    this->mediator->NotifyInvertabrate(this,"INVALID::NF",nullptr);
    return false;
  }
  auto NeededRule = this->rules[creature->name];
  bool valid_qty = creature->qty < NeededRule.Maximum_Qty;
  bool valid_size;
  if(NeededRule.Minimum_Size ==9999)
  {
    valid_size = true;
  }
  else
  {
    valid_size = creature->size > NeededRule.Minimum_Size;
  }
  if(valid_qty&&valid_size)
  {
    this->mediator->NotifyInvertabrate(this,"VALID",creature);
    return true;
  }
  if(!valid_size)
  {
    this->mediator->NotifyInvertabrate(this,"INVALID::SIZE",nullptr);
  }
  if(!valid_qty)
  {
    this->mediator->NotifyInvertabrate(this,"INVALID::QTY",nullptr);
  }
  return false;
}
void InvertabrateChecker::LoadRules()
{
  const std::string PATH = "INVERTABRATE_RULES.txt";
  std::ifstream file_reader(PATH);
  std::string buffer;
  while(std::getline(file_reader,buffer))
  {
    std::vector<std::string> split = this->SplitFileData(buffer);
    FishRules rule;
    rule.Group = split.at(0);
    rule.Species = split.at(1);
    rule.Minimum_Size = std::stof(split.at(2));
    rule.Maximum_Qty = std::stoi(split.at(3));
    this->rules[split.at(1)] = rule;
  }
}
std::unordered_map<std::string, std::vector<std::string>> InvertabrateChecker::getSpecies()
{
  std::unordered_map<std::string,std::vector<std::string>> map;
  for(auto& [key, value]:this->rules)
  {
    if(map.find(value.Group)==map.end())
    {
      map[value.Group] = {key};
    }
    else
    {
      map[value.Group].push_back(key);
    }
  }
  return map;
}
void InvertabrateChecker::CleanUp()
{
  this->mediator = nullptr;
}
void InvertabrateChecker::SetMediator(Mediator* mediator)
{
  this->mediator = mediator;
}

#endif
