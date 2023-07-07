#ifndef RPN_CALCULATOR_H
#define RPN_CALCULATOR_H

#include <string>
#include <list>
#include <vector>
#include <map>
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
      void resolveAndApplyOperation(EquationMember operation, std::list<EquationMember>& notation);
      EquationToRpnTransformer rpnTransformer;
      double calculationResult_;
      std::map<EquationMemberType, std::function<double(double, double)>> binaryOperation_ = {
        {PLUS, [](double a, double b) { return a + b; }}
      };

  };
} // namespaces s21 


#endif /* RPN_CALCULATOR_H */