#include "SeaChecker.cpp"
#include "InvertabrateCreature.cpp"
#include "Mediator.cpp"
#include <fstream>
#include <regex>
class VertabrateChecker: public SeaChecker
{
  public:
  void LoadRules() override;
  void CleanUp() override;
  void SetMediator(Mediator* mediator);
  bool CheckVertabrateCreature(VertabrateCreature* creature);

  protected:
  Mediator* mediator;
  std::vector<std::string> SplitFileData(std::string& line);
};
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
