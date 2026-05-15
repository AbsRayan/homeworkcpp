#pragma once

#include "primitive_expressions.h"

#include <memory>
#include <map>
#include <string>

class ExpressionFactory
{
public:
    ExpressionFactory()
    {
        for (int i = MinCachedConstant; i <= MaxCachedConstant; ++i)
        {
            createConstant(i);
        }
    }
    std::shared_ptr<Constant> createConstant(double value)
    {
        auto it = constants.find(value);
        if (it != constants.end())
        {
            return it->second;
        }
        auto constant = std::make_shared<Constant>(value);
        constants[value] = constant;

        return constant;
    }

    std::shared_ptr<Variable> createVariable(const std::string& name)
    {
        auto it = variables.find(name);
        if (it != variables.end())
        {
            return it->second;
        }
        auto variable = std::make_shared<Variable>(name);
        variables[name] = variable;

        return variable;
    }

private:
    static constexpr int MinCachedConstant = -5;
    static constexpr int MaxCachedConstant = 256;

    std::map<std::string, std::shared_ptr<Variable>> variables;
    std::map<double, std::shared_ptr<Constant>> constants;
};