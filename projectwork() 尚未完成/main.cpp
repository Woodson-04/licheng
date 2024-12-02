# include <iostream>
# include <string>

#include "expression_evaluator.h"

int main()
{
    List cinList();
    std::string expression;
    std::cout << "Please Enter an operation Expresstion:";
    std::getline(std::cin, expression);
    /*cinExpreesion(expression, cinList);
    postOperationExpression(cinList, postOperationList);
    return operation(postOperationList);*/
    std::cout<<expression<<std::endl;
};
