#ifndef RPN_CALCULATOR_H
#define RPN_CALCULATOR_H

#include <string>
#include <list>
#include <vector>
#include <map>
#include <math.h>
#include <functional>
#include "EquationToRpnTransformer.h"

namespace s21 {
  class RpnCalculator {
    public:
      RpnCalculator() : calculationResult_{ 0 } {}
      double calculate(const std::string& equation);
    private:
      std::vector<std::string> splitBySpace(const std::string& equation);
      void calculateRpnNotation(std::list<EquationMember>& notation);
      void resolveAndApplyOperation(EquationMember operation, std::list<EquationMember>& notation, std::list<EquationMember>::iterator itSign);
      EquationToRpnTransformer rpnTransformer;
      double calculationResult_;
      std::map<EquationMemberType, std::function<double(double, double)>> binaryOperation_ = {
        {PLUS, [](double a, double b) { return a + b; }},
        {MINUS, [](double a, double b) { return a - b; }},
        {MULTI, [](double a, double b) { return a * b; }},
        {DIVISION, [](double a, double b) { return a / b; }},
        {MOD, [](double a, double b) { return fmod(a, b); }},
        {POWER, [](double a, double b) { return pow(a, b); }}
      };
      std::map<EquationMemberType, std::function<double(double)>> prefixFucntion_ = {
        {SIN, [](double a) { return sin(a); }},
        {ASIN,[](double a) { return asin(a); }},
        {COS, [](double a) { return cos(a); }},
        {ACOS, [](double a) { return acos(a); }},
        {TAN, [](double a) {return tan(a); }},
        {ATAN, [](double a) { return atan(a); }},
        {LOG, [](double a) { return log2(a); }},
        {LN, [](double a) { return log(a); }},
        {SQRT, [](double a) { return sqrt(a); }}
      };
  };
} // namespaces s21 


#endif /* RPN_CALCULATOR_H */