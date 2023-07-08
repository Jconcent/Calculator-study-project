#ifndef RPN_CALCULATOR_H
#define RPN_CALCULATOR_H

#include <string>
#include <list>
#include <vector>
#include <map>
#include <math.h>
#include "EquationToRpnTransformer.h"

#ifdef DEBUG
#include <iostream>
#endif

namespace s21 {
  class RpnCalculator {
    public:
      RpnCalculator() : calculationResult_{ 0 } {}
      double calculate(const std::string& equation);
    private:
      std::vector<std::string> splitBySpace(const std::string& equation);
      void calculateRpnNotation(std::list<EquationMember>& notation);
      void resolveAndApplyOperation(EquationMember operation, std::list<EquationMember>& notation, std::list<EquationMember>::iterator itSign);
      void debug(std::list<EquationMember>& notation);
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
        {COS, [](double a) { return cos(a); }}
      };
  };
} // namespaces s21 


#endif /* RPN_CALCULATOR_H */