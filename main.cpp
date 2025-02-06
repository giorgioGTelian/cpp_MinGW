#include <iostream>
#include <string>
#include <vector>

// Function to demonstrate basic input/output
void basicIO() {
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Hello, " << name << "!" << std::endl;
}

// Function to demonstrate control structures
void controlStructures() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (number > 0) {
        std::cout << "The number is positive." << std::endl;
    } else if (number < 0) {
        std::cout << "The number is negative." << std::endl;
    } else {
        std::cout << "The number is zero." << std::endl;
    }

    std::cout << "Counting from 1 to " << number << ":" << std::endl;
    for (int i = 1; i <= number; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Function to demonstrate vectors
void vectorDemo() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Vector elements: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Class to demonstrate object-oriented programming
class Rectangle {
private:
    int width, height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    int area() {
        return width * height;
    }

    void display() {
        std::cout << "Rectangle with width " << width << " and height " << height << " has an area of " << area() << std::endl;
    }
};

// Main function to test all functionalities
int main() {
    std::cout << "Testing Basic I/O:" << std::endl;
    basicIO();

    std::cout << "\nTesting Control Structures:" << std::endl;
    controlStructures();

    std::cout << "\nTesting Vectors:" << std::endl;
    vectorDemo();

    std::cout << "\nTesting Classes and Objects:" << std::endl;
    Rectangle rect(10, 5);
    rect.display();

    return 0;
}