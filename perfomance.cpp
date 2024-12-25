#include <iostream>
#include <memory>
#include "header.h"

double Leaf::evaluate() const{
    return value;
}

BinaryOperator::BinaryOperator(std::unique_ptr<Node>&& left, std::unique_ptr<Node>&& right) 
        : left(std::move(left)), right(std::move(right)) {};

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

