#include "CalculationController.h"

namespace s21 {
    long double CalculationController::calculate(std::string equation) {
        return calculator.Calculate(equation);
    }
} // s21