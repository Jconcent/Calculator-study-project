#ifndef EQUATION_TO_RPN_TRANSFORMER_H
#define EQUATION_TO_RPN_TRANSFORMER_H

#include <string>
#include <stack>
#include <vector>
#include <list>
#include <map>
#include "EquationMember.h"

#ifdef DEBUG
#include <iostream>
#endif

namespace s21 {
  class EquationToRpnTransformer {
    public:
      EquationToRpnTransformer() {}
      std::list<EquationMember> transformEquation(std::vector<std::string> equationMembers);
    private:
      void processEquationMember(std::string member);
      bool isNumberMember(std::string member);
      bool isBinaryOperation(std::string member);
      void resolvePriority(EquationMember member);
      void moveAllOperationToResult();
      void debug();
      std::stack<EquationMember> operationsStack_;
      std::list<EquationMember> resultNotation_;
      std::map<std::string, EquationMemberType> binaryOperations_ = {
        {"+", PLUS}
      };
      std::map<EquationMemberType, int> priorityByType_ = {
        {PLUS, 1}
      };
  };
} // namespaces s21 


#endif /* EQUATION_TO_RPN_TRANSFORMER_H */