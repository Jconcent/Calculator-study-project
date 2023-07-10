#include "RpnCalculator.h"
#include <iostream>

int main() {
  s21::RpnCalculator calc;
  auto result = calc.calculate("log ( 1 / 2.234 ) ^ 2");
  std::cout << "result: " << result << '\n';
  return 0;
}