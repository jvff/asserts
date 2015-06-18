#ifndef EXPRESSION_ITERATOR_HPP
#define EXPRESSION_ITERATOR_HPP

#include <string>
#include <vector>

class ExpressionIterator {
private:
    std::vector<std::string> resultingExpressions;
    std::vector<std::string>::iterator iterator;
    std::vector<std::string>::iterator endOfExpressions;

    void parse(const std::string& expression);

public:
    ExpressionIterator(const std::string& expression) {
        parse(expression);

        iterator = resultingExpressions.begin();
        endOfExpressions = resultingExpressions.end();
    }

    ExpressionIterator& operator++() {
        ++iterator;

        return *this;
    }

    const std::string& operator*() const {
        return *iterator;
    }

    bool hasMore() const {
        return iterator != endOfExpressions;
    }
};

#endif
