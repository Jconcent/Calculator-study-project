#include "RpnCalculator.h"
#include <iostream>

int main() {
  s21::RpnCalculator calc;
  auto result = calc.calculate("0 - ( 5 + sqrt ( 9.123 ) )");
  std::cout << "result: " << result << '\n';
  return 0;
}