#ifndef RPN_CALCULATOR_H
#define RPN_CALCULATOR_H

#include <string>
#include <vector>
#include "EquationToRpnTransformer.h"

#ifdef DEBUG
#include <iostream>
#endif

namespace s21 {
  class RpnCalculator {
    public:
      RpnCalculator() {}
      double calculate(const std::string& equation);
    private:
      std::vector<std::string> splitBySpace(const std::string& equation);
      EquationToRpnTransformer rpnTransformer;

  };
} // namespaces s21 


#endif /* RPN_CALCULATOR_H */