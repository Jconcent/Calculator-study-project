#include "RpnCalculator.h"

namespace s21 {
  double RpnCalculator::calculate(const std::string& equation) {
    auto equationMembers = splitBySpace(equation);

    #ifdef DEBUG
      std::cout << "DEBUG AFTER SPLIT\n";
      for (auto splitString : equationMembers) {
        std::cout << "DEBUG: " << splitString << '\n';
      }
      std::cout << '\n';
    #endif

    auto resultNotation = rpnTransformer.transformEquation(equationMembers);

    #ifdef DEBUG
      std::cout << "DEBUG AFTER TRANSFORM\n";
      for (auto notationMember : resultNotation) {
        std::cout << "DEBUG: " << notationMember << '\n';
      }
      std::cout << '\n';
    #endif
    
    return 0.0;
  }

  std::vector<std::string> RpnCalculator::splitBySpace(const std::string& equation) {
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