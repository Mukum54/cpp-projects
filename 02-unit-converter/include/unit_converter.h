#pragma once
#include <string>

namespace UnitConverter {
    // Temperature
    double celsiusToFahrenheit(double celsius);
    double fahrenheitToCelsius(double fahrenheit);

    // Length
    double metersToFeet(double meters);
    double feetToMeters(double feet);

    // Weight
    double kilogramsToPounds(double kg);
    double poundsToKilograms(double lbs);

    // Currency (simplified)
    double usdToEur(double usd);
    double eurToUsd(double eur);

    // Input validation
    bool isNumber(const std::string& s);
}