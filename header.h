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
    
    // Метод evaluate возвращает значение листа
    double evaluate() const override;
};

class BinaryOperator : public Node {
protected:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
public:
    BinaryOperator(std::unique_ptr<Node>&& left, std::unique_ptr<Node>&& right)
        : left(std::move(left)), right(std::move(right)) {}
};

class Add : public BinaryOperator {
public:
    using BinaryOperator::BinaryOperator;
    
    // Метод evaluate выполняет сложение значений левого и правого поддерева
    double evaluate() const override;
};

// Узел вычитания
class Subtract : public BinaryOperator {
public:
    using BinaryOperator::BinaryOperator;
    
    // Метод evaluate выполняет вычитание значений левого и правого поддерева
    double evaluate() const override;
};

// Узел умножения
class Multiply : public BinaryOperator {
public:
    using BinaryOperator::BinaryOperator;
    
    //умножение значений левого и правого поддерева
    double evaluate() const override;
};

// Узел деления
class Divide : public BinaryOperator {
public:
    using BinaryOperator::BinaryOperator;
    
    //деление значений левого и правого поддерева
    double evaluate() const override;
};
