#ifndef CALCULATOR_STUDY_PROJECT_SRC_MODEL_EQUATION_TO_RPN_TRANSFORMER_H
#define CALCULATOR_STUDY_PROJECT_SRC_MODEL_EQUATION_TO_RPN_TRANSFORMER_H

#include <string>
#include <stack>
#include <vector>
#include <list>
#include <map>
#include "EquationMember.h"

namespace s21 {
    class EquationToRpnTransformer {
    public:
        EquationToRpnTransformer() {}

        std::list<EquationMember> transformEquation(std::vector<std::string> equationMembers);

    private:
        void processEquationMember(std::string member);

        bool isNumberMember(std::string member);

        bool isBinaryOperation(std::string member);

        bool isBracket(std::string member);

        bool isPrefixFunction(std::string member);

        void resolvePriority(EquationMember member);

        void moveAllOperationToResult();

        void bracketProcess(std::string member);

        std::stack<EquationMember> operationsStack_;
        std::list<EquationMember> resultNotation_;
        std::map<std::string, EquationMemberType> binaryOperations_ = {
                {"+",   PLUS},
                {"-",   MINUS},
                {"*",   MULTI},
                {"/",   DIVISION},
                {"mod", MOD},
                {"^",   POWER}
        };
        std::map<std::string, EquationMemberType> prefixFunction_ = {
                {"sin",  SIN},
                {"cos",  COS},
                {"asin", ASIN},
                {"acos", ACOS},
                {"tan",  TAN},
                {"atan", ATAN},
                {"sqrt", SQRT},
                {"log",  LOG},
                {"ln",   LN}
        };
        std::map<EquationMemberType, int> priorityByType_ = {
                {PLUS,     1},
                {MINUS,    1},
                {MULTI,    5},
                {DIVISION, 5},
                {MOD,      5},
                {POWER,    7},
                {SIN,      10},
                {ASIN,     10},
                {COS,      10},
                {ACOS,     10},
                {TAN,      10},
                {ATAN,     10},
                {SQRT,     10},
                {LOG,      10},
                {LN,       10}
        };
    };
} // namespaces s21 


#endif // CALCULATOR_STUDY_PROJECT_SRC_MODEL_EQUATION_TO_RPN_TRANSFORMER_H