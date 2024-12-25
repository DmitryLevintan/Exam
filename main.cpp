#include "perfomance.cpp"
#include <iostream>
#include <memory>


int main() {
    // Создаем дерево выражений
    auto tree = std::make_unique<Add>(
        std::make_unique<Multiply>(std::make_unique<Leaf>(2), std::make_unique<Leaf>(3)),
        std::make_unique<Subtract>(std::make_unique<Leaf>(10), std::make_unique<Leaf>(6))
    );
    
    // Вычисляем значение выражения
    std::cout << "Result: " << tree->evaluate() << std::endl;
    
    return 0;
}