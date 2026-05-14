#pragma once

#include "checkpoint.h"
#include "checkpoint_builder.h"

#include <vector>
#include <memory>

class RouteDirector
{
public:
    void buildRoute(const std::vector<std::unique_ptr<Checkpoint>>& route, CheckpointBuilder& builder) const
    {
        for (int i = 0; i < route.size(); ++i) 
        {
            route[i]->build(builder, i + 1);
        }
    }
};