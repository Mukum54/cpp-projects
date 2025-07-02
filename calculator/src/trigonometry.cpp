#include "../include/math_utils.h"  
#include <cmath>  

namespace AdvancedMath {  
    // Converts degrees to radians  
    double degreesToRadians(double degrees) {  
        return degrees * (M_PI / 180.0);  
    }  

    // Trigonometric functions  
    double sine(double angleDegrees) { return std::sin(degreesToRadians(angleDegrees)); }  
    double cosine(double angleDegrees) { return std::cos(degreesToRadians(angleDegrees)); }  
    double tangent(double angleDegrees) { return std::tan(degreesToRadians(angleDegrees)); }  
}  