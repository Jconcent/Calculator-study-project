#include "RpnCalculator.h"

namespace s21 {
    double RpnCalculator::calculate(const std::string &equation) {
        auto equationMembers = splitBySpace(equation);
        auto resultNotation = rpnTransformer.transformEquation(equationMembers);

        while (resultNotation.size() != 1) {
            calculateRpnNotation(resultNotation);
        }

        return (*resultNotation.begin()).getValue();
    }

    void RpnCalculator::calculateRpnNotation(std::list<EquationMember> &notation) {
        auto it = notation.begin();
        while (it != notation.end()) {
            if (it->getType() != NUMBER) {
                resolveAndApplyOperation(*it, notation, it);
                break;
            }
            it++;
        }
    }

    void RpnCalculator::resolveAndApplyOperation(EquationMember operation, std::list<EquationMember> &notation,
                                                 std::list<EquationMember>::iterator itSign) {
        auto signPos = itSign;
        double result;
        if (binaryOperation_.count(operation.getType()) > 0) {
            auto second = (--itSign)->getValue();
            auto first = (--itSign)->getValue();
            result = binaryOperation_[operation.getType()](first, second);
        } else if (prefixFunction_.count(operation.getType()) > 0) {
            auto targetNumber = (--itSign)->getValue();
            result = prefixFunction_[operation.getType()](targetNumber);
        }
        auto positionForNewMember = notation.erase(itSign, ++signPos);
        notation.emplace(positionForNewMember, EquationMember(result, NUMBER));
    }

    std::vector<std::string> RpnCalculator::splitBySpace(const std::string &equation) {
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