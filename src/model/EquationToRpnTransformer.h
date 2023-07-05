#ifndef EQUATION_TO_RPN_TRANSFORMER_H
#define EQUATION_TO_RPN_TRANSFORMER_H

#include <string>
#include <stack>
#include <vector>

#ifdef DEBUG
#include <iostream>
#endif

namespace s21 {
  class EquationToRpnTransformer {
    public:
      EquationToRpnTransformer() {}
      std::vector<std::string> transformEquation(std::vector<std::string> equationMembers);
    private:
      void processEquationMember(std::string member);
      bool isNumberMember(std::string member);
      std::stack<std::string> operationsStack_;
      std::vector<std::string> resultNotation_;
  };
} // namespaces s21 


#endif /* EQUATION_TO_RPN_TRANSFORMER_H */