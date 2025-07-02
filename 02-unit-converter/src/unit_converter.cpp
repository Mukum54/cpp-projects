#include "../include/unit_converter.h"
#include <cmath>

namespace UnitConverter {
    // Temperature
    double celsiusToFahrenheit(double celsius) { 
        return (celsius * 9/5) + 32; 
    }
    
    double fahrenheitToCelsius(double fahrenheit) { 
        return (fahrenheit - 32) * 5/9; 
    }

    // Length (1 meter ≈ 3.28084 feet)
    double metersToFeet(double meters) { 
        return meters * 3.28084; 
    }
    
    double feetToMeters(double feet) { 
        return feet / 3.28084; 
    }

    // Weight (1 kg ≈ 2.20462 lbs)
    double kilogramsToPounds(double kg) { 
        return kg * 2.20462; 
    }
    
    double poundsToKilograms(double lbs) { 
        return lbs / 2.20462; 
    }

    // Currency (simplified rates)
    double usdToEur(double usd) { 
        return usd * 0.85;  // 1 USD = 0.85 EUR
    }
    
    double eurToUsd(double eur) { 
        return eur / 0.85; 
    }

    // Input validation
    bool isNumber(const std::string& s) {
        try {
            std::stod(s);
            return true;
        } catch (...) {
            return false;
        }
    }
}