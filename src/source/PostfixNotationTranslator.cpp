#include "../headers/PostfixNotationTranslator.h"
#include <stack>

std::vector<std::string> reader::postfix_notation_translator::vec;
std::shared_ptr<spdlog::logger> reader::postfix_notation_translator::logger = spdlog::basic_logger_mt("postfix_notation_translator", "logs/postfix-notation-translator-logs.txt");;

reader::postfix_notation_translator::postfix_notation_translator() { }

reader::postfix_notation_translator 
reader::postfix_notation_translator::in_vector(const std::vector<std::string>& vec) {
    postfix_notation_translator::vec = vec;
    postfix_notation_translator::logger->info("added vector {}", fmt::join(vec, ", "));
    return postfix_notation_translator();
}

std::vector<std::string>
reader::postfix_notation_translator::get() {
    postfix_notation_translator::logger->info("converting to postfix notation...");
    return postfix_notation_translator::handle_data();
}

std::vector<std::string>
reader::postfix_notation_translator::handle_data() {
    std::vector<std::string> output;
    std::stack<std::string> operators;

    std::unordered_map<std::string, int> precedence{
        {"+", 1}, {"-", 1},
        {"*", 2}, {"/", 2},
        {"sin", 3}, {"cos", 3}, {"sqrt", 3}, {"ln", 3},
        {"^", 4}
    };

    std::unordered_map<std::string, bool> right_associative{
        {"^", true}
    };

    for (const auto& token : vec) {
        if (is_number(token)) {
            output.push_back(token);
        } else if (is_math_action(token)) {
            postfix_notation_translator::logger->info("Token '{}' identified as operator", token);
            if (is_unary_function(token)) {
                postfix_notation_translator::logger->info("Unary function '{}' pushed to stack", token);
                operators.push(token);
            } else {
                while (!operators.empty() &&
                       (precedence[operators.top()] > precedence[token] || 
                        (precedence[operators.top()] == precedence[token] && !right_associative[token]))) {
                    postfix_notation_translator::logger->info("Operator '{}' popped to output due to precedence", operators.top());
                    output.push_back(operators.top());
                    operators.pop();
                }
                operators.push(token);
                postfix_notation_translator::logger->info("Operator '{}' pushed to stack", token);
            }
        } else if (token == "(") {
            postfix_notation_translator::logger->info("Left parenthesis '(' pushed to stack");
            operators.push(token);
        } else if (token == ")") {
            postfix_notation_translator::logger->info("Right parenthesis ')' encountered, popping operators until '('");
            while (!operators.empty() && operators.top() != "(") {
                output.push_back(operators.top());
                operators.pop();
            }
            if (!operators.empty()) {
                operators.pop();
                postfix_notation_translator::logger->info("Left parenthesis '(' popped from stack");
            }
            if (!operators.empty() && is_unary_function(operators.top())) {
                postfix_notation_translator::logger->info("Unary function '{}' popped to output after ')'", operators.top());
                output.push_back(operators.top());
                operators.pop();
            }
        }
    }

    while (!operators.empty()) {
        postfix_notation_translator::logger->info("Remaining operator '{}' popped to output", operators.top());
        output.push_back(operators.top());
        operators.pop();
    }

    postfix_notation_translator::logger->info("Postfix notation conversion complete: {}", fmt::join(output, ", "));
    return output;
}

bool reader::postfix_notation_translator::is_unary_function(const std::string& token) {
    return (token == "cos" || token == "sin" || token == "sqrt" || token == "ln");
}

bool reader::postfix_notation_translator::is_math_action(const std::string& a) {
    return (a == "+" || a == "-" || a == "*" || a == "/" || a == "^" || 
            a == "cos" || a == "sin" || a == "sqrt" || a == "ln");
}

bool reader::postfix_notation_translator::is_number(const std::string& token) {
    return !token.empty() && std::all_of(token.begin(), token.end(), ::isdigit);
}