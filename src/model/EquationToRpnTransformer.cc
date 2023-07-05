#include "EquationToRpnTransformer.h"

namespace s21 {
  std::vector<std::string> EquationToRpnTransformer::transformEquation(std::vector<std::string> equationMembers) {
    for (auto equationMember : equationMembers) {
      processEquationMember(equationMember);
    }
    return equationMembers;
  }

  void EquationToRpnTransformer::processEquationMember(std::string member) {
    if (isNumberMember(member)) {
      #ifdef DEBUG
        std::cout << "DEBUG: MEMBER " << member << " IS NUMBER\n";
      #endif
    } else {
      #ifdef DEBUG
        std::cout << "DEBUG: MEMBER " << member << " IS NOT NUMBER\n";
      #endif
    }
  }

  bool EquationToRpnTransformer::isNumberMember(std::string member) {
    return member.find_first_not_of("0123456789.") == std::string::npos;
  }
}