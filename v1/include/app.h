#ifndef APP
#define APP
#include <memory>
#include "Mediator.h"
class App 
{
  public: 
  void SetUp() const;
  void Run() const;
  void Cleanup() const;
  App();

  private:
  std::unique_ptr<Mediator> engine;
};
#endif
