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

        std::list<EquationMember> TransformEquation(std::vector<std::string> equation_members);

    private:
        void ProcessEquationMember(std::string member);

        bool IsNumberMember(std::string member);

        bool IsBinaryOperation(std::string member);

        bool IsBracket(std::string member);

        bool IsPrefixFunction(std::string member);

        void ResolvePriority(EquationMember member);

        void MoveAllOperationToResult();

        void BracketProcess(std::string member);

        std::stack<EquationMember> operations_stack_;
        std::list<EquationMember> result_notation_;
        std::map<std::string, EquationMemberType> binary_operations_ = {
                {"+",   PLUS},
                {"-",   MINUS},
                {"*",   MULTI},
                {"/",   DIVISION},
                {"mod", MOD},
                {"^",   POWER}
        };
        std::map<std::string, EquationMemberType> prefix_function_ = {
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
        std::map<EquationMemberType, int> priority_by_type_ = {
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