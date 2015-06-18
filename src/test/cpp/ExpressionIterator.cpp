#include "pegtl.hh"

#include "ExpressionIterator.hpp"

#define RULE(name, ...) \
struct name : __VA_ARGS__ {}

#define ALIAS(newName, oldName) \
using newName = oldName

#define ALIAS_T(newName, oldName) ALIAS_TEMPLATE(typename, newName, oldName)
#define ALIAS_C(newName, oldName) ALIAS_TEMPLATE(char, newName, oldName)

#define ALIAS_TEMPLATE(type, newName, oldName) \
template <type... T> \
ALIAS(newName, oldName<T...>)

ALIAS(any, pegtl::ascii::any);
ALIAS_C(literal, pegtl::ascii::string);
ALIAS_C(notA, pegtl::not_one);
ALIAS_T(oneOf, pegtl::sor);
ALIAS_T(oneOrMore, pegtl::plus);
ALIAS_T(sequence, pegtl::seq);
ALIAS_T(zeroOrMore, pegtl::star);

RULE(escapedChar, sequence<literal<'\\'>, any>);

RULE(charForLiteralChar, oneOf<escapedChar, any>);
RULE(literalChar, sequence<literal<'\''>, charForLiteralChar, literal<'\''> >);

RULE(stringChar, oneOf<escapedChar, notA<'\"'> >);
RULE(stringChars, zeroOrMore<stringChar>);
RULE(literalString, sequence<literal<'\"'>, stringChars, literal<'\"'> >);

struct parenthesisGroup;
struct bracketGroup;
struct braceGroup;
struct angleBracketGroup;

template <char endChar>
RULE(insideGroupExpression, oneOf<parenthesisGroup, bracketGroup, braceGroup,
        angleBracketGroup, literalChar, literalString, notA<endChar> >);

template <char endChar>
RULE(insideGroup, zeroOrMore<insideGroupExpression<endChar> >);

template <char open, char close>
RULE(group, sequence<literal<open>, insideGroup<close>, literal<close> >);

RULE(parenthesisGroup, group<'(', ')'>);
RULE(bracketGroup, group<'[', ']'>);
RULE(braceGroup, group<'{', '}'>);
RULE(angleBracketGroup, sequence<notA<' '>, group<'<', '>'> >);

RULE(expressionAlternatives, oneOf<parenthesisGroup, bracketGroup, braceGroup,
        angleBracketGroup, literalChar, literalString,
        notA<',', '(', '[', '{'> >);
RULE(expression, oneOrMore<expressionAlternatives>);

RULE(expressions, zeroOrMore<sequence<literal<','>, expression> >);
RULE(expressionList, sequence<expression, expressions>);

template <typename Rule>
struct action : pegtl::nothing<Rule> {};

template <>
struct action<expression> {
    static void apply(const pegtl::input& input,
            std::vector<std::string>& expressions) {
        std::string result = input.string();
        size_t startPos = result.find_first_not_of(" \t\n\r");
        size_t endPos = result.find_last_not_of(" \t\n\r");
        size_t length = endPos - startPos + 1;

        if (startPos != std::string::npos)
            expressions.push_back(result.substr(startPos, length));
    }
};

void ExpressionIterator::parse(const std::string& expression) {
    pegtl::parse<expressionList, action>(expression, "", resultingExpressions);
}
