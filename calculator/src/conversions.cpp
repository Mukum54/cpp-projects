#include "../include/calculator.h"  
#include <cmath>  

namespace Calculator {  
    // Binary → Decimal (e.g., "1101" → 13)  
    int binaryToDecimal(const std::string& binary) {  
        int decimal = 0;  
        for (size_t i = 0; i < binary.length(); ++i) {  
            if (binary[i] == '1') {  
                decimal += static_cast<int>(std::pow(2, binary.length() - 1 - i));  
            }  
        }  
        return decimal;  
    }  

    // Decimal → Binary (e.g., 13 → "1101")  
    std::string decimalToBinary(int decimal) {  
        if (decimal == 0) return "0";  
        std::string binary;  
        while (decimal > 0) {  
            binary = (decimal % 2 == 0 ? "0" : "1") + binary;  
            decimal /= 2;  
        }  
        return binary;  
    }  
}  