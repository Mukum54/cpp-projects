#include "../include/calculator.h"  
#include <cmath>  
#include <sstream>  

namespace Calculator {  
    // Basic Operations  
    double add(double a, double b) { return a + b; }  
    double subtract(double a, double b) { return a - b; }  
    double multiply(double a, double b) { return a * b; }  

    // Division with zero-check  
    double divide(double a, double b) {  
        if (b == 0) throw std::runtime_error("Error: Division by zero");  
        return a / b;  
    }  

    // Square root with validation  
    double sqrt(double x) {  
        if (x < 0) throw std::runtime_error("Error: Negative sqrt input");  
        return std::sqrt(x);  
    }  

    // Modulus (integers only)  
    int modulus(int a, int b) {  
        if (b == 0) throw std::runtime_error("Error: Modulus by zero");  
        return a % b;  
    }  

    // Validates numeric input  
    bool isNumber(const std::string& s) {  
        std::istringstream iss(s);  
        double dummy;  
        return (iss >> dummy) && iss.eof();  
    }  

    // Validates binary input (e.g., "1010")  
    bool isBinary(const std::string& s) {  
        for (char c : s) {  
            if (c != '0' && c != '1') return false;  
        }  
        return !s.empty();  
    }  
}  