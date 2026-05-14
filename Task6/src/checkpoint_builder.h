#pragma once

#include <string>

class CheckpointBuilder
{
    public:
    virtual ~CheckpointBuilder() = default;
    
    virtual void addMandatoryCheckpoint(int number, const std::string& name, double latitude, double longitude) = 0;
    virtual void addOptionalCheckpoint(int number, const std::string& name, double latitude, double longitude, double penalty) = 0;
};