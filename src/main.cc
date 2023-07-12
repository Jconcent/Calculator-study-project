#include "controller/CalculationController.h"
#include <iostream>

// Однажды, я найду время, что установить VPN и поставить QT. И тогда возможно калькулятор обретет UI

int main() {
  std::string equation;
  s21::CalculationController controller;
  getline(std::cin, equation);
  auto result = controller.calculate(equation);
  std::cout << "result: " << result << '\n';
  return 0;
}