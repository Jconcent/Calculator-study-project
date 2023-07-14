#ifndef CALCULATOR_STUDY_PROJECT_SRC_MODEL_RPN_CALCULATOR_H
#define CALCULATOR_STUDY_PROJECT_SRC_MODEL_RPN_CALCULATOR_H

#include <string>
#include <list>
#include <vector>
#include <map>
#include <math.h>
#include <functional>
#include "equation_to_rpn_transformer.h"

namespace s21 {
    class RpnCalculator {
    public:
        RpnCalculator() = default;

        double Calculate(const std::string &equation);

    private:
        std::vector<std::string> SplitBySpace(const std::string &equation);

        void CalculateRpnNotation(std::list<EquationMember> &notation);

        void ResolveAndApplyOperation(EquationMember operation, std::list<EquationMember> &notation,
                                      std::list<EquationMember>::iterator it_sign);

        EquationToRpnTransformer rpn_transformer_;
        std::map<EquationMemberType, std::function<double(double, double)>> binary_operation_ = {
                {PLUS,     [](double a, double b) { return a + b; }},
                {MINUS,    [](double a, double b) { return a - b; }},
                {MULTI,    [](double a, double b) { return a * b; }},
                {DIVISION, [](double a, double b) { return a / b; }},
                {MOD,      [](double a, double b) { return fmod(a, b); }},
                {POWER,    [](double a, double b) { return pow(a, b); }}
        };
        std::map<EquationMemberType, std::function<double(double)>> prefix_function_ = {
                {SIN,  [](double a) { return sin(a); }},
                {ASIN, [](double a) { return asin(a); }},
                {COS,  [](double a) { return cos(a); }},
                {ACOS, [](double a) { return acos(a); }},
                {TAN,  [](double a) { return tan(a); }},
                {ATAN, [](double a) { return atan(a); }},
                {LOG,  [](double a) { return log10(a); }},
                {LN,   [](double a) { return log(a); }},
                {SQRT, [](double a) { return sqrt(a); }}
        };
    };
} // namespaces s21 


#endif // CALCULATOR_STUDY_PROJECT_SRC_MODEL_RPN_CALCULATOR_H