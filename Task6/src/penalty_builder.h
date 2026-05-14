#pragma once

#include "checkpoint_builder.h"

class PenaltyBuilder : public CheckpointBuilder
{
public:
    PenaltyBuilder() : totalPenalty_(0.0) {}

    void addMandatoryCheckpoint(int number, const std::string& name, double latitude, double longitude) override
    {
    }

    void addOptionalCheckpoint(int number, const std::string& name, double latitude, double longitude, double penalty) override
    {
        totalPenalty_ += penalty;
    }

    double getTotalPenalty() const
    {
        return totalPenalty_;
    }

private:
    double totalPenalty_;
};