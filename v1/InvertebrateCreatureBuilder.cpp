#include "SeaCreatureBuilder.cpp"
#include "InvertebrateCreature.cpp"

class InvertebrateCreatureBuilder: public ISeaCreatureBuilder
{
    public: 
    InvertebrateCreatureBuilder()
    {
        InvertebrateCreature _temp;
    }
    
    std::unique_ptr<InvertebrateCreature> Builder()
    {
        return std::move(this->_value);
    }
    protected:
    std::unique_ptr<InvertebrateCreature> _value;
    virtual void _reset() = 0;
};