#ifndef RPN_CALCULATOR_H
#define RPN_CALCULATOR_H

#include <string>
#include <vector>

namespace rpn {

enum class TokenType {
    Number,
    Operator,
    LeftParen,
    RightParen
};

struct Token {
    TokenType type;
    double number;
    char symbol;
};

struct CalculationResult {
    bool ok;
    double value;
    std::string error;
};

std::vector<Token> tokenize(const std::string& expression);
std::vector<Token> toReversePolishNotation(const std::vector<Token>& tokens);
double evaluateReversePolishNotation(const std::vector<Token>& tokens);
CalculationResult calculate(const std::string& expression);

}  // namespace rpn

#endif
