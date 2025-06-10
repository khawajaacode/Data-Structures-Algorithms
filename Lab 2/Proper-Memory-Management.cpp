#include <iostream>
#include <memory>

std::unique_ptr<int> createSafePointer() {
    return std::make_unique<int>(42);
}

int main() {
    std::unique_ptr<int> ptr = createSafePointer();
    std::cout << *ptr ;// Safe access
    return 0;
}
