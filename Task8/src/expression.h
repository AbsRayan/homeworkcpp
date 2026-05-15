#pragma once

#include <map>
#include <string>
#include <ostream>

class Expression
{
public:
    virtual ~Expression() = default;

    virtual double calculate(const std::map<std::string, double>& context) const = 0;
    virtual void print(std::ostream& out) const = 0;
};