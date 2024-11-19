# include <iostream>
# include <string>

#include "expression_evaluator.h"

int main()
{
    std::cout << "Please Enter an operation Expresstion:";
    std::getline(std::cin, expression);
    cinExpreesion(expression, cinList);
    postOperationExpression(cinList, postOperationList);
    return operation(postOperationList);
};
