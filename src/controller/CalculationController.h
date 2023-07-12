#ifndef CALCULATOR_STUDY_PROJECT_SRC_CONTROLLER_CALCULATION_CONTROLLER_H
#define CALCULATOR_STUDY_PROJECT_SRC_CONTROLLER_CALCULATION_CONTROLLER_H

#include "../model/RpnCalculator.h"

namespace s21 {

    class CalculationController {
    public:
        CalculationController() {};

        long double calculate(std::string equation);

    private:
        RpnCalculator calculator;
    };

} // s21

#endif //CALCULATOR_STUDY_PROJECT_SRC_CONTROLLER_CALCULATION_CONTROLLER_H
