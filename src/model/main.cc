#include "RpnCalculator.h"
#include <iostream>

int main() {
  s21::RpnCalculator calc;
  auto result = calc.calculate("12 + cos ( 2 ^ 8 ) + 100 + 15 * 7 / sin ( 0.5 ) + 30 / 10 / 10 * 5 * ( 10 + ( 10 + sin ( 0.5 ) ) )");
  std::cout << "result: " << result << '\n';
  return 0;
}