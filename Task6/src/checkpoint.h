#pragma once

#include "checkpoint_builder.h"

#include <string>
#include <stdexcept>

class Checkpoint
{
public:
    Checkpoint(const std::string& name, double latitude, double longitude)
        : name_(name), latitude_(latitude), longitude_(longitude) 
    {
        validateCoordinates(latitude, longitude);
    }
    
    virtual ~Checkpoint() = default;

    const std::string& name() const 
    {
        return name_;
    }

    double latitude() const 
    {
        return latitude_;
    }

    double longitude() const 
    {
        return longitude_;
    }

    virtual void build(CheckpointBuilder& builder, int number) const = 0;
private:
    std::string name_;
    double latitude_;
    double longitude_;

    static void validateCoordinates(double latitude, double longitude)
    {
        if (latitude < -90.0 || latitude > 90.0) 
        {
            throw std::out_of_range("Latitude must be between -90 and 90 degrees.");
        }
        if (longitude < -180.0 || longitude > 180.0) 
        {
            throw std::out_of_range("Longitude must be between -180 and 180 degrees.");
        }

    }
};

class MandatoryCheckpoint : public Checkpoint
{
public:
    MandatoryCheckpoint(const std::string& name, double latitude, double longitude)
        : Checkpoint(name, latitude, longitude) 
    {
    }

    void build(CheckpointBuilder& builder, int number) const override
    {
        builder.addMandatoryCheckpoint(number, name(), latitude(), longitude());
    }
};

class OptionalCheckpoint : public Checkpoint
{
public:
    OptionalCheckpoint(const std::string& name, double latitude, double longitude, double penalty)
        : Checkpoint(name, latitude, longitude), penalty_(penalty)
    {
        if (penalty < 0.0) 
        {
            throw std::invalid_argument("Penalty must be a non-negative value.");
        }
    }

    double penalty() const 
    {
        return penalty_;
    }

    void build(CheckpointBuilder& builder, int number) const override
    {
        builder.addOptionalCheckpoint(number, name(), latitude(), longitude(), penalty());
    }

private:
    double penalty_;
};