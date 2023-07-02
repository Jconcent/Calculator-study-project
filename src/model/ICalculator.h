#ifndef I_CALCULATOR_H
#define I_CALCULATOR_H

#include <string>

namespace s21 {
  class ICalculator {
    public:
      virtual double calculate(std::string equation) = 0;
  };
}

#endif /* I_CALCULATOR_H */