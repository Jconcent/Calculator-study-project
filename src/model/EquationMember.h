#ifndef EQUATION_MEMBER_H
#define EQUATION_MEMBER_H

#include <string>
#include "EquationMemberType.h"

#ifdef DEBUG
#include <iostream>
#endif

namespace s21 {
  class EquationMember {
    public:
      EquationMember(long double value, EquationMemberType type) : value_{ value }, type_{ type } {};
      EquationMember(EquationMemberType type) : value_{0}, type_{ type } {};
      long double getValue() {
        return value_;
      }
      EquationMemberType getType() {
        return type_;
      }
    private:
      long double value_;
      EquationMemberType type_;
  };
} // namespaces s21 


#endif /* EQUATION_MEMBER_H */