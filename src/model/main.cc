#include "RpnCalculator.h"
#include <iostream>

int main() {
  s21::RpnCalculator calc;
  auto result = calc.calculate("2 + 3 + 4 + 5 + 6 + 7");
  std::cout << "result: " << result << '\n';
  return 0;
}