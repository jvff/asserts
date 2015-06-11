#ifndef EXPRESSION_REG_EX_HPP
#define EXPRESSION_REG_EX_HPP

#include <regex>

class ExpressionRegEx {
public:
    static std::regex& getRegEx();

private:
    std::regex regex;

    ExpressionRegEx();
};

#endif
