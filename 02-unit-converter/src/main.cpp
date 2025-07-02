#include "../include/unit_converter.h"
#include <iostream>
#include <limits>
#include <string>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayMenu() {
    std::cout << "\n📏 Unit Converter\n";
    std::cout << "1. Temperature\n";
    std::cout << "2. Length\n";
    std::cout << "3. Weight\n";
    std::cout << "4. Currency\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose category (1-5): ";
}

void handleTemperature() {
    double value;
    std::string input;
    char choice;

    std::cout << "\n🌡️ Temperature Converter\n";
    std::cout << "a) Celsius → Fahrenheit\n";
    std::cout << "b) Fahrenheit → Celsius\n";
    std::cout << "Choice (a/b): ";
    std::cin >> choice;

    std::cout << "Enter value: ";
    std::cin >> input;
    if (!UnitConverter::isNumber(input)) {
        std::cerr << "❌ Invalid number!\n";
        clearInputBuffer();
        return;
    }
    value = std::stod(input);

    switch (choice) {
        case 'a': 
            std::cout << "Result: " << UnitConverter::celsiusToFahrenheit(value) << " °F\n";
            break;
        case 'b':
            std::cout << "Result: " << UnitConverter::fahrenheitToCelsius(value) << " °C\n";
            break;
        default:
            std::cerr << "❌ Invalid choice!\n";
    }
}

void handleLength() {
    double value;
    std::string input;
    char choice;

    std::cout << "\n📏 Length Converter\n";
    std::cout << "a) Meters → Feet\n";
    std::cout << "b) Feet → Meters\n";
    std::cout << "Choice (a/b): ";
    std::cin >> choice;

    std::cout << "Enter value: ";
    std::cin >> input;
    if (!UnitConverter::isNumber(input)) {
        std::cerr << "❌ Invalid number!\n";
        clearInputBuffer();
        return;
    }
    value = std::stod(input);

    switch (choice) {
        case 'a':
            std::cout << "Result: " << UnitConverter::metersToFeet(value) << " ft\n";
            break;
        case 'b':
            std::cout << "Result: " << UnitConverter::feetToMeters(value) << " m\n";
            break;
        default:
            std::cerr << "❌ Invalid choice!\n";
    }
}

void handleWeight() {
    double value;
    std::string input;
    char choice;

    std::cout << "\n⚖️ Weight Converter\n";
    std::cout << "a) Kilograms → Pounds\n";
    std::cout << "b) Pounds → Kilograms\n";
    std::cout << "Choice (a/b): ";
    std::cin >> choice;

    std::cout << "Enter value: ";
    std::cin >> input;
    if (!UnitConverter::isNumber(input)) {
        std::cerr << "❌ Invalid number!\n";
        clearInputBuffer();
        return;
    }
    value = std::stod(input);

    switch (choice) {
        case 'a':
            std::cout << "Result: " << UnitConverter::kilogramsToPounds(value) << " lbs\n";
            break;
        case 'b':
            std::cout << "Result: " << UnitConverter::poundsToKilograms(value) << " kg\n";
            break;
        default:
            std::cerr << "❌ Invalid choice!\n";
    }
}

void handleCurrency() {
    double value;
    std::string input;
    char choice;

    std::cout << "\n💵 Currency Converter\n";
    std::cout << "a) USD → EUR\n";
    std::cout << "b) EUR → USD\n";
    std::cout << "Choice (a/b): ";
    std::cin >> choice;

    std::cout << "Enter value: ";
    std::cin >> input;
    if (!UnitConverter::isNumber(input)) {
        std::cerr << "❌ Invalid number!\n";
        clearInputBuffer();
        return;
    }
    value = std::stod(input);

    switch (choice) {
        case 'a':
            std::cout << "Result: " << UnitConverter::usdToEur(value) << " EUR\n";
            break;
        case 'b':
            std::cout << "Result: " << UnitConverter::eurToUsd(value) << " USD\n";
            break;
        default:
            std::cerr << "❌ Invalid choice!\n";
    }
}

int main() {
    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cerr << "❌ Invalid input! Please enter a number (1-5).\n";
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                handleTemperature();
                break;
            case 2:
                handleLength();
                break;
            case 3:
                handleWeight();
                break;
            case 4:
                handleCurrency();
                break;
            case 5:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cerr << "❌ Invalid choice! Please select 1-5.\n";
        }
    }
}