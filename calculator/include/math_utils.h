#pragma once
#include <cmath> // For sin(), cos(), tan(), M_PI

namespace AdvancedMath {
    // Converts degrees to radians (e.g., 180° → π radians)
    double degreesToRadians(double degrees);

    // Trigonometric functions (input in degrees)
    double sine(double angleDegrees);    // sin(θ)
    double cosine(double angleDegrees);  // cos(θ)
    double tangent(double angleDegrees); // tan(θ)
}