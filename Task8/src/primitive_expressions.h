#pragma once

#include "expression.h"

class Constant : public Expression
{
public:
    explicit Constant(double value) : value(value) {}

    double calculate(const std::map<std::string, double>& context) const override
    {
        return value;
    }

    void print(std::ostream& out) const override
    {
        out << value;
    }

    double getValue() const
    {
        return value;
    }

private:
    double value;
};

class Variable : public Expression
{
public:
    explicit Variable(const std::string& name) : name(name) {}

    double calculate(const std::map<std::string, double>& context) const override
    {
        auto it = context.find(name);
        if (it != context.end())
        {
            return it->second;
        }
        throw std::runtime_error("Variable not found in context: " + name);
    }

    void print(std::ostream& out) const override
    {
        out << name;
    }

    const std::string& getName() const
    {
        return name;
    }
    
private:
    std::string name;
};