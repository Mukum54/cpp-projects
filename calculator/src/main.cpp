#include "../include/calculator.h"
#include "../include/math_utils.h"
#include <iostream>
#include <limits>
#include <string>

// Clears invalid input from cin
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Displays the main menu
void displayMenu() {
    std::cout << "\n🔢 **Multi-Feature Calculator**\n";
    std::cout << "1. Basic Arithmetic (+, -, *, /, √, %)\n";
    std::cout << "2. Binary → Decimal Conversion\n";
    std::cout << "3. Decimal → Binary Conversion\n";
    std::cout << "4. Quadratic Equation Solver\n";
    std::cout << "5. Trigonometry Functions (Student Feature)\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option (1-6): ";
}

// Handles basic arithmetic operations
void handleBasicArithmetic() {
    double num1, num2;
    char op;
    std::string input;

    std::cout << "\nEnter first number: ";
    std::cin >> input;
    if (!Calculator::isNumber(input)) {
        std::cerr << "❌ Invalid number!\n";
        clearInputBuffer();
        return;
    }
    num1 = std::stod(input);

    std::cout << "Enter operator (+, -, *, /, %, s for √): ";
    std::cin >> op;

    if (op != 's') { // Square root only needs one input
        std::cout << "Enter second number: ";
        std::cin >> input;
        if (!Calculator::isNumber(input)) {
            std::cerr << "❌ Invalid number!\n";
            clearInputBuffer();
            return;
        }
        num2 = std::stod(input);
    }

    try {
        switch (op) {
            case '+': std::cout << "Result: " << Calculator::add(num1, num2); break;
            case '-': std::cout << "Result: " << Calculator::subtract(num1, num2); break;
            case '*': std::cout << "Result: " << Calculator::multiply(num1, num2); break;
            case '/': std::cout << "Result: " << Calculator::divide(num1, num2); break;
            case '%': std::cout << "Result: " << Calculator::modulus((int)num1, (int)num2); break;
            case 's': std::cout << "√(" << num1 << ") = " << Calculator::sqrt(num1); break;
            default: std::cerr << "❌ Invalid operator!\n";
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

// Handles binary-to-decimal conversion
void handleBinaryToDecimal() {
    std::string binary;
    std::cout << "\nEnter binary number (e.g., 1101): ";
    std::cin >> binary;

    if (!Calculator::isBinary(binary)) {
        std::cerr << "❌ Invalid binary number (only 0s and 1s allowed)!\n";
        clearInputBuffer();
        return;
    }

    std::cout << "Decimal: " << Calculator::binaryToDecimal(binary) << "\n";
}

// Handles decimal-to-binary conversion
void handleDecimalToBinary() {
    std::string input;
    std::cout << "\nEnter decimal number: ";
    std::cin >> input;

    if (!Calculator::isNumber(input)) {
        std::cerr << "❌ Invalid number!\n";
        clearInputBuffer();
        return;
    }

    int decimal = std::stoi(input);
    std::cout << "Binary: " << Calculator::decimalToBinary(decimal) << "\n";
}

// Handles quadratic equation solver
void handleQuadraticSolver() {
    double a, b, c;
    std::string input;

    std::cout << "\nEnter coefficients (a, b, c) for ax² + bx + c = 0:\n";
    std::cout << "a: ";
    std::cin >> input;
    if (!Calculator::isNumber(input)) {
        std::cerr << "❌ Invalid input for 'a'!\n";
        clearInputBuffer();
        return;
    }
    a = std::stod(input);

    std::cout << "b: ";
    std::cin >> input;
    if (!Calculator::isNumber(input)) {
        std::cerr << "❌ Invalid input for 'b'!\n";
        clearInputBuffer();
        return;
    }
    b = std::stod(input);

    std::cout << "c: ";
    std::cin >> input;
    if (!Calculator::isNumber(input)) {
        std::cerr << "❌ Invalid input for 'c'!\n";
        clearInputBuffer();
        return;
    }
    c = std::stod(input);

    try {
        double root1, root2;
        bool isComplex;
        Calculator::solveQuadratic(a, b, c, root1, root2, isComplex);

        if (isComplex) {
            std::cout << "Roots: " << root1 << " + " << root2 << "i and "
                      << root1 << " - " << root2 << "i\n";
        } else {
            std::cout << "Roots: " << root1 << " and " << root2 << "\n";
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

// Handles trigonometry functions (student-added feature)
void handleTrigonometry() {
    double angle;
    std::string input;

    std::cout << "\nEnter angle in degrees: ";
    std::cin >> input;
    if (!Calculator::isNumber(input)) {
        std::cerr << "❌ Invalid angle!\n";
        clearInputBuffer();
        return;
    }
    angle = std::stod(input);

    std::cout << "sin(" << angle << "°) = " << AdvancedMath::sine(angle) << "\n";
    std::cout << "cos(" << angle << "°) = " << AdvancedMath::cosine(angle) << "\n";
    std::cout << "tan(" << angle << "°) = " << AdvancedMath::tangent(angle) << "\n";
}

int main() {
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cerr << "❌ Invalid choice (enter a number 1-6)!\n";
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: handleBasicArithmetic(); break;
            case 2: handleBinaryToDecimal(); break;
            case 3: handleDecimalToBinary(); break;
            case 4: handleQuadraticSolver(); break;
            case 5: handleTrigonometry(); break;
            case 6: std::cout << "Exiting...\n"; return 0;
            default: std::cerr << "❌ Invalid choice (1-6 only)!\n";
        }
    }
}