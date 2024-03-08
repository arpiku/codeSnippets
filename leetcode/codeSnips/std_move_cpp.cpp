
#include <iostream>
#include <vector>
#include <string>

class SimpleString {
public:
    std::string data;

    SimpleString(const std::string& str) : data(str) {
        std::cout << "Constructed with data: " << data << std::endl;
    }

    // Move constructor
    SimpleString(SimpleString&& other) noexcept : data(std::move(other.data)) {
        std::cout << "Move-constructed with data: " << data << std::endl;
        other.data = ""; // Optional, but a good practice to leave the moved-from object in a predictable state
    }

    // Move assignment operator
    SimpleString& operator=(SimpleString&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);
            std::cout << "Move-assigned with data: " << data << std::endl;
            other.data = ""; // Clear the other data
        }
        return *this;
    }
};

int main() {
    SimpleString original("Hello, World!");
    SimpleString moved_to = std::move(original); // Invokes the move constructor

    std::cout << "Original after move: " << original.data << std::endl;
    std::cout << "Moved to: " << moved_to.data << std::endl;

    SimpleString another("Goodbye!");
    moved_to = std::move(another); // Invokes the move assignment operator

    std::cout << "Another after move: " << another.data << std::endl;
    std::cout << "Moved to after reassignment: " << moved_to.data << std::endl;
}
