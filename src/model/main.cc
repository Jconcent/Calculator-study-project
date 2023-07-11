#include "../controller/CalculationController.h"
#include <iostream>

// Однажды, я найду время, что установить VPN и поставить QT. И тогда возможно калькулятор обретет UI

int main() {
  s21::CalculationController controller;
  auto result = controller.calculate("log ( 1 / 2.234 ) ^ 2");
  std::cout << "result: " << result << '\n';
  return 0;
}