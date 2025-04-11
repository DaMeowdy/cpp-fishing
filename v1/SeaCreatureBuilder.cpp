#pragma once
#include <memory>
class ISeaCreatureBuilder {
    public: 
    ~ISeaCreatureBuilder() = default;

    protected:
    virtual void _reset() = 0;
};