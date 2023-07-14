#include "equation_to_rpn_transformer.h"

namespace s21 {
    std::list<EquationMember> EquationToRpnTransformer::TransformEquation(std::vector<std::string> equation_members) {
        for (auto equation_member: equation_members) {
            ProcessEquationMember(equation_member);
        }
        MoveAllOperationToResult();
        return result_notation_;
    }

    void EquationToRpnTransformer::ProcessEquationMember(std::string member) {
        if (IsNumberMember(member)) {
            result_notation_.push_back(EquationMember(std::stold(member), NUMBER));
        } else if (IsBinaryOperation(member)) {
            ResolvePriority(EquationMember(binary_operations_[member]));
        } else if (IsBracket(member)) {
            BracketProcess(member);
        } else if (IsPrefixFunction(member)) {
            operations_stack_.push(EquationMember(prefix_function_[member]));
        }
    }

    bool EquationToRpnTransformer::IsNumberMember(std::string member) {
        return member.find_first_not_of("0123456789.") == std::string::npos;
    }

    bool EquationToRpnTransformer::IsBinaryOperation(std::string member) {
        return binary_operations_.count(member) > 0;
    }

    bool EquationToRpnTransformer::IsBracket(std::string member) {
        return member == "(" || member == ")";
    }

    bool EquationToRpnTransformer::IsPrefixFunction(std::string member) {
        return prefix_function_.count(member) > 0;
    }

    void EquationToRpnTransformer::ResolvePriority(EquationMember member) {
        if (operations_stack_.empty()) {
            operations_stack_.push(member);
            return;
        }
        auto new_member_priority = priority_by_type_[member.getType()];
        while (!operations_stack_.empty() && priority_by_type_[operations_stack_.top().getType()] >= new_member_priority) {
            result_notation_.push_back(operations_stack_.top());
            operations_stack_.pop();
        }
        operations_stack_.push(member);
    }

    void EquationToRpnTransformer::MoveAllOperationToResult() {
        while (!operations_stack_.empty()) {
            result_notation_.push_back(operations_stack_.top());
            operations_stack_.pop();
        }
    }

    void EquationToRpnTransformer::BracketProcess(std::string member) {
        if (member == "(") {
            operations_stack_.push(EquationMember(BRACKET));
        } else {
            while (operations_stack_.top().getType() != BRACKET) {
                result_notation_.push_back(operations_stack_.top());
                operations_stack_.pop();
            }
            operations_stack_.pop();
        }
    }
}