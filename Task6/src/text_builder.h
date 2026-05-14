#pragma once

#include "checkpoint_builder.h"
#include <iomanip>
#include <sstream>
#include <iostream>

class TextBuilder : public CheckpointBuilder
{
public:
    void addMandatoryCheckpoint(int number, const std::string& name, double latitude, double longitude) override
    {
        output_ << name << " (cp " << number << ")"
                << " (" << std::fixed << std::setprecision(2) << latitude 
                << ",  " << std::fixed << std::setprecision(2) << longitude << ")"
                << std::endl;
    }

    void addOptionalCheckpoint(int number, const std::string& name, double latitude, double longitude, double penalty) override
    {
        output_ << name << " (cp " << number << ")"
                << " (" << std::fixed << std::setprecision(2) << latitude 
                << ",  " << std::fixed << std::setprecision(2) << longitude 
                << ") - penalty: " << penalty 
                << std::endl;
    }

    std::string print() const
    {
        return  output_.str();
    }

private:
    std::ostringstream output_;
};