#include "ExpressionRegEx.hpp"

#define RX_EXPRESSION "(?:" RX_EXPRESSION_ALTERNATIVES ")+"

#define RX_EXPRESSION_ALTERNATIVES \
    RX_NOT_COMMA "|" \
    RX_PARENTHESIS_GROUP "|" \
    RX_BRACE_GROUP "|" \
    RX_BRACKET_GROUP "|" \
    RX_COMMA_CHAR "|" \
    RX_STRING

#define RX_STRING \
    RX_DOUBLE_QUOTES \
    "(?:" RX_ESCAPED "|" RX_NOT_DOUBLE_QUOTES ")*" \
    RX_DOUBLE_QUOTES

#define RX_PARENTHESIS_GROUP RX_GROUP(PARENTHESIS)
#define RX_BRACKET_GROUP RX_GROUP(BRACKET)
#define RX_BRACE_GROUP RX_GROUP(BRACE)

#define RX_GROUP(Group) \
    RX_OPEN_##Group \
    "(?:" RX_INNER_##Group##_EXPRESSION ")*" \
    RX_CLOSE_##Group

#define RX_INNER_EXPRESSION(Group) \
    RX_STRING "|" \
    RX_CHAR "|" \
    RX_NOT_CLOSE_##Group

#define RX_OPEN_BRACE "\\{"
#define RX_INNER_BRACE_EXPRESSION RX_INNER_EXPRESSION(BRACE)
#define RX_CLOSE_BRACE "\\}"

#define RX_OPEN_BRACKET "\\["
#define RX_INNER_BRACKET_EXPRESSION RX_INNER_EXPRESSION(BRACKET)
#define RX_CLOSE_BRACKET "\\]"

#define RX_OPEN_PARENTHESIS "\\("
#define RX_INNER_PARENTHESIS_EXPRESSION RX_INNER_EXPRESSION(PARENTHESIS)
#define RX_CLOSE_PARENTHESIS "\\)"

#define RX_COMMA_CHAR "','"
#define RX_CHAR "'.'"

#define RX_ESCAPED "\\\\."

#define RX_NOT_COMMA "[^,]"
#define RX_NOT_CLOSE_BRACE "[^}]"
#define RX_NOT_CLOSE_BRACKET "[^]]"
#define RX_NOT_CLOSE_PARENTHESIS "[^)]"
#define RX_NOT_DOUBLE_QUOTES "[^\"]"

#define RX_DOUBLE_QUOTES "\""

static ExpressionRegEx* instance = NULL;

std::regex& ExpressionRegEx::getRegEx() {
    if (instance == NULL)
        instance = new ExpressionRegEx();

    return instance->regex;
}

ExpressionRegEx::ExpressionRegEx() : regex(RX_EXPRESSION) {
}
