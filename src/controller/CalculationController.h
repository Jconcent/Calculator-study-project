#ifndef CALCULATOR_STUDY_PROJECT_CALCULATION_CONTROLLER_H
#define CALCULATOR_STUDY_PROJECT_CALCULATION_CONTROLLER_H

#include "RpnCalculator.h"
#ifdef DEBUG
#include <iostream>
#endif

namespace s21 {

    class CalculationController {
    public:
        CalculationController() {};
        long double calculate(std::string equation);
    private:
        RpnCalculator calculator;
    };

} // s21

#endif //CALCULATOR_STUDY_PROJECT_CALCULATION_CONTROLLER_H
