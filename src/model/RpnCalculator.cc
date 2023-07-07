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
    while (resultNotation.size() != 1) {
      calculateRpnNotation(resultNotation);
    }
    return (*resultNotation.begin()).getValue();
  }

  void RpnCalculator::calculateRpnNotation(std::list<EquationMember>& notation) {
    for (auto operation : notation) {
      if (operation.getType() != NUMBER) {
        resolveAndApplyOperation(operation, notation);
        break;
      }
    }
  }

  void RpnCalculator::resolveAndApplyOperation(EquationMember operation, std::list<EquationMember>& notation) {
    if (binaryOperation_.count(operation.getType()) > 0) {
      auto first = (*notation.begin()).getValue();
      auto second = (*(++notation.begin())).getValue();
      auto result = binaryOperation_[operation.getType()](first, second);
      notation.pop_front();
      notation.pop_front();
      notation.pop_front();
      notation.push_front(EquationMember(result, NUMBER));
    }
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