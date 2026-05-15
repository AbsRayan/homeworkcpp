#pragma once

#include "binary_operation.h"

class Addition : public BinaryOperation
{
public:
    Addition(
        std::shared_ptr<Expression> left,
        std::shared_ptr<Expression> right
    )
        : BinaryOperation(left, right) {}

    double calculate(const std::map<std::string, double>& context) const override
    {
        return left->calculate(context) + right->calculate(context);
    }

    void print(std::ostream& out) const override
    {
        out << "(";
        left->print(out);
        out << " + ";
        right->print(out);
        out << ")";
    }
};

class Subtraction : public BinaryOperation
{
public:
    Subtraction(
        std::shared_ptr<Expression> left,
        std::shared_ptr<Expression> right
    )
        : BinaryOperation(left, right) {}

    double calculate(const std::map<std::string, double>& context) const override
    {
        return left->calculate(context) - right->calculate(context);
    }

    void print(std::ostream& out) const override
    {
        out << "(";
        left->print(out);
        out << " - ";
        right->print(out);
        out << ")";
    }
};

class Multiplication : public BinaryOperation
{
public:
    Multiplication(
        std::shared_ptr<Expression> left,
        std::shared_ptr<Expression> right
    )
        : BinaryOperation(left, right) {}

    double calculate(const std::map<std::string, double>& context) const override
    {
        return left->calculate(context) * right->calculate(context);
    }

    void print(std::ostream& out) const override
    {
        out << "(";
        left->print(out);
        out << " * ";
        right->print(out);
        out << ")";
    }
};

class Division : public BinaryOperation
{
public:
    Division(
        std::shared_ptr<Expression> left,
        std::shared_ptr<Expression> right
    )
        : BinaryOperation(left, right) {}

    double calculate(const std::map<std::string, double>& context) const override
    {
        double denominator = right->calculate(context);
        if (denominator == 0)
        {
            throw std::runtime_error("Division by zero");
        }
        return left->calculate(context) / denominator;
    }

    void print(std::ostream& out) const override
    {
        out << "(";
        left->print(out);
        out << " / ";
        right->print(out);
        out << ")";
    }
};