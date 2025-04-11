
#include <iostream>;
#include <conio.h>;
class IApp {
    public: 
    virtual void Run() = 0;
    private:
    virtual bool _recursiveRuntimeLoop(bool& isRunning) = 0;
    virtual void _clearScreen() = 0;
    virtual void _drawMenu() = 0;
};

class App : IApp {
    public:
    void Run() override
    {
        bool is_running_currently = true;
        this->_recursiveRuntimeLoop(is_running_currently);
    }
    private:
    bool _recursiveRuntimeLoop(bool& isRunning) override
    {
        this->_drawMenu();
        this->_clearScreen();
        return _recursiveRuntimeLoop(isRunning);
    }
    void _drawMenu() override
    {
        
    }
    void _clearScreen() override
    {
        printf("\033c");
    }
};
int main()
{
    return 0;
}