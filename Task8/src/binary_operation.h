#pragma once

#include "expression.h"

#include <memory>

class BinaryOperation : public Expression
{
public:
    BinaryOperation(
        std::shared_ptr<Expression> left,
        std::shared_ptr<Expression> right
    )
        : left(left), right(right) {}

    virtual ~BinaryOperation() = default;

protected:
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;
};
    