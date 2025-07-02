#pragma once  
#include <string>  
#include <stdexcept>  

namespace Calculator {  
    // Basic Arithmetic  
    double add(double a, double b);  
    double subtract(double a, double b);  
    double multiply(double a, double b);  
    double divide(double a, double b);  
    double sqrt(double x);  
    int modulus(int a, int b);  

    // Binary ↔ Decimal  
    int binaryToDecimal(const std::string& binary);  
    std::string decimalToBinary(int decimal);  

    // Quadratic Solver  
    void solveQuadratic(double a, double b, double c, double& root1, double& root2, bool& isComplex);  

    // Input Validation  
    bool isNumber(const std::string& s);  
    bool isBinary(const std::string& s);  
}  