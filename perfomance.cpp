#include <iostream>
#include <memory>
#include "header.h"

double Leaf::evaluate() const{
    return value;
}


double Add::evaluate() const {
        return left->evaluate() + right->evaluate();
}

double Subtract::evaluate() const {
        return left->evaluate() - right->evaluate();
}

double Multiply::evaluate() const {
        return left->evaluate() * right->evaluate();
}

double Divide::evaluate() const {
        return left->evaluate() / right->evaluate();
}

