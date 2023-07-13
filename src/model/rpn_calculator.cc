#include "rpn_calculator.h"

namespace s21 {
    double RpnCalculator::Calculate(const std::string &equation) {
        auto equation_members = SplitBySpace(equation);
        auto result_notation = rpn_transformer_.transformEquation(equation_members);

        while (result_notation.size() != 1) {
            CalculateRpnNotation(result_notation);
        }

        return (*result_notation.begin()).getValue();
    }

    void RpnCalculator::CalculateRpnNotation(std::list<EquationMember> &notation) {
        auto it = notation.begin();
        while (it != notation.end()) {
            if (it->getType() != NUMBER) {
                ResolveAndApplyOperation(*it, notation, it);
                break;
            }
            it++;
        }
    }

    void RpnCalculator::ResolveAndApplyOperation(EquationMember operation, std::list<EquationMember> &notation,
                                                 std::list<EquationMember>::iterator it_sign) {
        auto sign_pos = it_sign;
        double result;
        if (binary_operation_.count(operation.getType()) > 0) {
            auto second = (--it_sign)->getValue();
            auto first = (--it_sign)->getValue();
            result = binary_operation_[operation.getType()](first, second);
        } else if (prefix_function_.count(operation.getType()) > 0) {
            auto target_number = (--it_sign)->getValue();
            result = prefix_function_[operation.getType()](target_number);
        }
        auto position_for_new_member = notation.erase(it_sign, ++sign_pos);
        notation.emplace(position_for_new_member, EquationMember(result, NUMBER));
    }

    std::vector<std::string> RpnCalculator::SplitBySpace(const std::string &equation) {
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