#ifndef RPN_CALCULATOR_H
#define RPN_CALCULATOR_H

#include "ICalculator.h"

namespace s21 {
  class RpnCalculator: public ICalculator {
    public:
      RpnCalculator() {}
      double calculate(std::string equation);
  };
} // namespaces s21 


#endif /* RPN_CALCULATOR_H */