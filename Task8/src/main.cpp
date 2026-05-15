#include "operations.h"
#include "espression_factory.h"

#include <iostream>

int main()
{
    ExpressionFactory factory;

    auto c1 = factory.createConstant(2);
    auto c2 = factory.createConstant(3);
    auto c3 = factory.createConstant(2);
    auto x1 = factory.createVariable("x");
    auto x2 = factory.createVariable("x");
    auto y = factory.createVariable("y");

    std::cout << (c1 == c3) << std::endl;
    std::cout << (x1 == x2) << std::endl;

    std::shared_ptr<Expression> expr =
        std::make_shared<Addition>(c1, x1);

    std::map<std::string, double> context = {{"x", 5}, {"y", 10}};

    expr->print(std::cout);
    std::cout << " = " << expr->calculate(context) << std::endl;

    return 0;
}