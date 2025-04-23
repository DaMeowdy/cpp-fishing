#include "SeaChecker.cpp"
#include "InvertabrateCreature.cpp"
#include "Mediator.cpp"
#include <fstream>
#include <regex>
#include <unordered_set>
class VertabrateChecker: public SeaChecker
{
  public:
  void LoadRules() override;
  void CleanUp() override;
  void SetMediator(Mediator* mediator);
  bool CheckVertabrateCreature(VertabrateCreature* creature);
  std::unordered_map<std::string, std::vector<std::string>> getSpecies();
  protected:
  Mediator* mediator;
  std::vector<std::string> SplitFileData(std::string& line);
};
std::unordered_map<std::string, std::vector<std::string>> VertabrateChecker::getSpecies()
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
void VertabrateChecker::LoadRules()
{
  const std::string PATH = "VERTABRATE_RULES.txt";
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
std::vector<std::string> VertabrateChecker::SplitFileData(std::string& line)
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
void VertabrateChecker::CleanUp()
{
  this->mediator = nullptr;
}
void VertabrateChecker::SetMediator(Mediator* mediator)
{
  this->mediator = mediator;
}
bool VertabrateChecker::CheckVertabrateCreature(VertabrateCreature* creature)
{
  if(this->rules.find(creature->name)==this->rules.end())
  {
    this->mediator->NotifyVertabrate(this,"INVALID::NF",nullptr);
    return false;
  }
  auto NeededRule = this->rules[creature->name];
  bool valid_qty = creature->qty < NeededRule.Maximum_Qty;
  bool valid_size = creature->size > NeededRule.Minimum_Size || NeededRule.Minimum_Size == 9999;
  if(valid_qty&&valid_size)
  {
    this->mediator->NotifyVertabrate(this,"VALID",creature);
    return true;
  }
  if(!valid_size)
  {
    this->mediator->NotifyVertabrate(this,"INVALID::SIZE",nullptr);
  }
  if(!valid_qty)
  {
    this->mediator->NotifyVertabrate(this,"INVALID::QTY",nullptr);
  }
  return false;
}
