#include "RpnCalculator.h"

namespace s21 {
  double RpnCalculator::calculate(std::string equation) {
    #ifdef DEBUG
      std::cout << "work" << '\n';
    #endif
    auto splited = splitBySpace(equation);
    #ifdef DEBUG
      std::cout << "splited string:\n" << splited[0] << " " << splited[1] << " " << splited[2] << '\n';
    #endif
    
    return 0.0;
  }

  std::vector<std::string> RpnCalculator::splitBySpace(std::string equation) {
    std::vector<std::string> result;
    size_t start = 0;

    for (size_t found = equation.find(" "); found != std::string::npos; found = equation.find(" ", start)) {
      result.push_back(std::string(equation.begin() + start, equation.begin() + found));
      start = found + 1;
    }
    if (start != equation.size()) {
      result.push_back(std::string(equation.begin() + start, equation.end()));
    }
    return result;
  }
};