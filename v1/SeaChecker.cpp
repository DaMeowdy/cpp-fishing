#include <unordered_map>
#include <vector>
#include "FishRules.cpp"
#ifndef SEA_CHECKER
#define SEA_CHECKER
class SeaChecker
{
  public:
  virtual void LoadRules() =0;
  virtual void CleanUp() = 0;
  protected:
  std::unordered_map<std::string, FishRules> rules;
};
#endif
