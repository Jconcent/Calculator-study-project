#ifndef RPN_CALCULATOR_H
#define RPN_CALCULATOR_H

#include <string>
#include <vector>

#ifdef DEBUG
#include <iostream>
#endif

namespace s21 {
  class RpnCalculator {
    public:
      RpnCalculator() {}
      double calculate(std::string equation);
    private:
      std::vector<std::string> splitBySpace(std::string equation);

  };
} // namespaces s21 


#endif /* RPN_CALCULATOR_H */