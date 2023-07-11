#include "CalculationController.h"

namespace s21 {
    long double CalculationController::calculate(std::string equation) {
        #ifdef DEBUG
        std::cout << "INPUT EQUATION " << equation;
        #endif
        return calculator.calculate(equation);
    }
} // s21