#include "RpnCalculator.h"
#include <iostream>

int main() {
  s21::RpnCalculator calc;
  auto result = calc.calculate("2.2 + 2");
  std::cout << "result: " << result << '\n';
  return 0;
}