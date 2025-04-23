#include "App.cpp"
int main()
{
  App app = App();
  app.SetUp();
  app.Run();
  app.Cleanup();
  return 0;
}
