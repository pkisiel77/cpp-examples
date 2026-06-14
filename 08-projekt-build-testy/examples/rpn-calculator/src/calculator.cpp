#include "rpn/calculator.h"

#include <cctype>
#include <stdexcept>
#include <string>
#include <vector>

namespace rpn {
namespace {

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char op) {
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

bool canStartSignedNumber(const std::vector<Token>& tokens) {
    return tokens.empty() || tokens.back().type == TokenType::Operator || tokens.back().type == TokenType::LeftParen;
}

bool isSignedNumberStart(const std::string& expression, std::size_t index, const std::vector<Token>& tokens) {
    const char ch = expression[index];
    if ((ch != '-' && ch != '+') || !canStartSignedNumber(tokens) || index + 1 >= expression.size()) {
        return false;
    }

    const char next = expression[index + 1];
    return std::isdigit(static_cast<unsigned char>(next)) || next == '.';
}

double applyOperator(char op, double left, double right) {
    switch (op) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            if (right == 0.0) {
                throw std::runtime_error("dzielenie przez zero");
            }
            return left / right;
        default:
            throw std::runtime_error("nieznany operator");
    }
}

}  // namespace

std::vector<Token> tokenize(const std::string& expression) {
    std::vector<Token> tokens;

    for (std::size_t i = 0; i < expression.size();) {
        const char ch = expression[i];

        if (std::isspace(static_cast<unsigned char>(ch))) {
            ++i;
            continue;
        }

        if (isSignedNumberStart(expression, i, tokens) || std::isdigit(static_cast<unsigned char>(ch)) || ch == '.') {
            std::size_t end = 0;
            const double value = std::stod(expression.substr(i), &end);
            tokens.push_back(Token{TokenType::Number, value, '\0'});
            i += end;
            continue;
        }

        if (isOperator(ch)) {
            tokens.push_back(Token{TokenType::Operator, 0.0, ch});
            ++i;
            continue;
        }

        if (ch == '(') {
            tokens.push_back(Token{TokenType::LeftParen, 0.0, ch});
            ++i;
            continue;
        }

        if (ch == ')') {
            tokens.push_back(Token{TokenType::RightParen, 0.0, ch});
            ++i;
            continue;
        }

        throw std::runtime_error("nieznany znak w wyrazeniu");
    }

    return tokens;
}

std::vector<Token> toReversePolishNotation(const std::vector<Token>& tokens) {
    std::vector<Token> output;
    std::vector<Token> operators;

    for (const Token& token : tokens) {
        if (token.type == TokenType::Number) {
            output.push_back(token);
        } else if (token.type == TokenType::Operator) {
            while (!operators.empty() && operators.back().type == TokenType::Operator &&
                   precedence(operators.back().symbol) >= precedence(token.symbol)) {
                output.push_back(operators.back());
                operators.pop_back();
            }
            operators.push_back(token);
        } else if (token.type == TokenType::LeftParen) {
            operators.push_back(token);
        } else if (token.type == TokenType::RightParen) {
            bool foundLeftParen = false;
            while (!operators.empty()) {
                Token top = operators.back();
                operators.pop_back();

                if (top.type == TokenType::LeftParen) {
                    foundLeftParen = true;
                    break;
                }

                output.push_back(top);
            }

            if (!foundLeftParen) {
                throw std::runtime_error("brakujacy nawias otwierajacy");
            }
        }
    }

    while (!operators.empty()) {
        Token top = operators.back();
        operators.pop_back();

        if (top.type == TokenType::LeftParen || top.type == TokenType::RightParen) {
            throw std::runtime_error("brakujacy nawias zamykajacy");
        }

        output.push_back(top);
    }

    return output;
}

double evaluateReversePolishNotation(const std::vector<Token>& tokens) {
    std::vector<double> stack;

    for (const Token& token : tokens) {
        if (token.type == TokenType::Number) {
            stack.push_back(token.number);
            continue;
        }

        if (token.type != TokenType::Operator || stack.size() < 2) {
            throw std::runtime_error("niepoprawne wyrazenie");
        }

        const double right = stack.back();
        stack.pop_back();
        const double left = stack.back();
        stack.pop_back();

        stack.push_back(applyOperator(token.symbol, left, right));
    }

    if (stack.size() != 1) {
        throw std::runtime_error("niepoprawne wyrazenie");
    }

    return stack.back();
}

CalculationResult calculate(const std::string& expression) {
    try {
        const std::vector<Token> tokens = tokenize(expression);
        const std::vector<Token> rpnTokens = toReversePolishNotation(tokens);
        return CalculationResult{true, evaluateReversePolishNotation(rpnTokens), ""};
    } catch (const std::exception& ex) {
        return CalculationResult{false, 0.0, ex.what()};
    }
}

}  // namespace rpn
