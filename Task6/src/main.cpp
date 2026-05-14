#include "checkpoint.h"
#include "text_builder.h"
#include "penalty_builder.h"
#include "route_director.h"
#include <iostream>

int main()
{
    std::vector<std::unique_ptr<Checkpoint>> route;
    route.push_back(std::make_unique<MandatoryCheckpoint>("Start", 45.05, 90.0));
    route.push_back(std::make_unique<OptionalCheckpoint>("Lake", 0.0, 0.0, 10.0));
    route.push_back(std::make_unique<OptionalCheckpoint>("Mountain", 60.0, 120.0, 20.0));

    RouteDirector director;
    TextBuilder textbuilder;

    director.buildRoute(route, textbuilder);

    std::cout << textbuilder.print();

    PenaltyBuilder penaltyBuilder;

    director.buildRoute(route, penaltyBuilder);

    std::cout << "Total Penalty: " << penaltyBuilder.getTotalPenalty() << std::endl;

    return 0;
}