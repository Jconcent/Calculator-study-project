#include "CalculationController.h"

namespace s21 {
    long double CalculationController::calculate(std::string equation) {
        return calculator.calculate(equation);
    }
} // s21