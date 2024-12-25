#include <iostream>
#include <memory>

class Node {
public:
    virtual double evaluate() const = 0;
};

class Leaf : public Node {
private:
    double value;
public:
    explicit Leaf(double value) : value(value) {}
    double evaluate() const override; // возвращает значение листа
};

class BinaryOperator : public Node {
protected:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
public:
    BinaryOperator(std::unique_ptr<Node>&& left, std::unique_ptr<Node>&& right);
};

class Add : public BinaryOperator {
public:
    using BinaryOperator::BinaryOperator;
    double evaluate() const override; // сложение значений
};

class Subtract : public BinaryOperator {
public:
    using BinaryOperator::BinaryOperator;
    double evaluate() const override; // сложение значений
};

class Multiply : public BinaryOperator {
public:
    using BinaryOperator::BinaryOperator;
    double evaluate() const override; // умножение значений
};

class Divide : public BinaryOperator {
public:
    using BinaryOperator::BinaryOperator;
    double evaluate() const override; // деление значений
};
