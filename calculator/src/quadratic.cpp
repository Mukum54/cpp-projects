#include "../include/calculator.h"  
#include <cmath>  

namespace Calculator {  
    // Solves ax² + bx + c = 0  
    void solveQuadratic(double a, double b, double c, double& root1, double& root2, bool& isComplex) {  
        if (a == 0) throw std::runtime_error("Error: 'a' cannot be zero");  

        double discriminant = b * b - 4 * a * c;  
        if (discriminant < 0) {  
            isComplex = true;  
            root1 = -b / (2 * a);  
            root2 = std::sqrt(-discriminant) / (2 * a);  
        } else {  
            isComplex = false;  
            root1 = (-b + std::sqrt(discriminant)) / (2 * a);  
            root2 = (-b - std::sqrt(discriminant)) / (2 * a);  
        }  
    }  
}  