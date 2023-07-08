#include "EquationToRpnTransformer.h"

namespace s21 {
  std::list<EquationMember> EquationToRpnTransformer::transformEquation(std::vector<std::string> equationMembers) {
    for (auto equationMember : equationMembers) {
      processEquationMember(equationMember);
    }
    moveAllOperationToResult();
    debug();
    return resultNotation_;
  }

  void EquationToRpnTransformer::processEquationMember(std::string member) {
    if (isNumberMember(member)) {
      resultNotation_.push_back(EquationMember(std::stold(member), NUMBER));
    } else if (isBinaryOperation(member)) {
      resolvePriority(EquationMember(binaryOperations_[member]));
    } else if (isBracket(member)) {
      bracketProcess(member);
    } else if (isPrefixFunction(member)) {
      operationsStack_.push(EquationMember(prefixFunction_[member]));
    }
  }

  bool EquationToRpnTransformer::isNumberMember(std::string member) {
    return member.find_first_not_of("0123456789.") == std::string::npos;
  }

  bool EquationToRpnTransformer::isBinaryOperation(std::string member) {
    return binaryOperations_.count(member) > 0;
  }

  bool EquationToRpnTransformer::isBracket(std::string member) {
    return member == "(" || member == ")";
  }

  bool EquationToRpnTransformer::isPrefixFunction(std::string member) {
    return prefixFunction_.count(member) > 0;
  }

  void EquationToRpnTransformer::resolvePriority(EquationMember member) {
    if (operationsStack_.empty()) {
      operationsStack_.push(member);
      return;
    }
    auto newMemberPriority = priorityByType_[member.getType()];
    while (!operationsStack_.empty() && priorityByType_[operationsStack_.top().getType()] >= newMemberPriority) {
      resultNotation_.push_back(operationsStack_.top());
      operationsStack_.pop();
    }
    operationsStack_.push(member);
  }

  void EquationToRpnTransformer::moveAllOperationToResult() {
    while (!operationsStack_.empty()) {
      resultNotation_.push_back(operationsStack_.top());
      operationsStack_.pop();
    }
  }

  void EquationToRpnTransformer::bracketProcess(std::string member) {
    if (member == "(") {
      operationsStack_.push(EquationMember(BRACKET));
    } else {
      while(operationsStack_.top().getType() != BRACKET) {
        resultNotation_.push_back(operationsStack_.top());
        operationsStack_.pop();
      }
      operationsStack_.pop();
    }
  }

  void EquationToRpnTransformer::debug() {
    #ifdef DEBUG
    std::cout << "DEBUG OPERATION STACK\n";
    while (!operationsStack_.empty()) {
      std::cout << "DEBUG " << "VALUE " << operationsStack_.top().getValue() << " AND TYPE " << operationsStack_.top().getType() << "\n";
      operationsStack_.pop();
    }
    std::cout << "\n";
    std::cout << "DEBUG RESULT NOTATION\n";
    for (auto resultMember : resultNotation_) {
      std::cout << "DEBUG: " << "VALUE " << resultMember.getValue() << " AND TYPE " << resultMember.getType() << '\n';
    }
    std::cout << "\n";
    #endif
  }
}