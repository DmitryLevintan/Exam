#include "perfomance.cpp"
#include <iostream>
#include <memory>

int main() {
    auto tree = std::make_unique<Add>(
        std::make_unique<Multiply>(std::make_unique<Leaf>(2), std::make_unique<Leaf>(3)),
        std::make_unique<Subtract>(std::make_unique<Leaf>(10), std::make_unique<Leaf>(6))
    );
    // Вычисляем значения. Для примера я взял (2*3) + (10-6)
    std::cout << "Result: " << tree->evaluate() << std::endl;
    
    return 0;
}