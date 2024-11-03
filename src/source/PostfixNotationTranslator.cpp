#include "../headers/PostfixNotationTranslator.h"
#include "../headers/Stack.h"
#include <stack>
std::vector<std::string> reader::postfix_notation_translator::vec;
std::shared_ptr<spdlog::logger> reader::postfix_notation_translator::logger = nullptr;

reader::postfix_notation_translator::postfix_notation_translator() {
    if (!logger) {
        logger = spdlog::basic_logger_mt("postfix_notation_translator", "logs/postfix-notation-translator.txt");
    }
}

reader::postfix_notation_translator 
reader::postfix_notation_translator::in_vector(const std::vector<std::string>& vec) {
    postfix_notation_translator::vec = vec;
    postfix_notation_translator instance;
    postfix_notation_translator::logger->info("added vector");
    return instance;
}

std::vector<std::string>
reader::postfix_notation_translator::get() {
    postfix_notation_translator::logger->info("converting to postfix notation");
    return postfix_notation_translator::handle_data();
}

std::vector<std::string> 
reader::postfix_notation_translator::handle_data() {
    std::vector<std::string> output;
    dsi::Stack<std::string> operators; // Using dsi::Stack instead of std::stack

    // Operator precedence and associativity mapping
    std::unordered_map<std::string, int> precedence {
        {"+", 1}, {"-", 1},
        {"*", 2}, {"/", 2},
        {"^", 3}
    };

    std::unordered_map<std::string, bool> right_associative {
        {"^", true}
    };

    for (const auto& token : vec) {
        if (is_number(token)) {
            output.push_back(token);
            logger->info("Added number {} to output", token);
        } else if (is_math_action(token)) {
            while (!operators.is_empty() && operators.peek() != "(" &&
                   ((right_associative.count(token) && precedence[token] < precedence[operators.peek()]) ||
                    (!right_associative.count(token) && precedence[token] <= precedence[operators.peek()]))) {
                
                // Safe pop and peek
                if (!operators.is_empty()) {
                    output.push_back(operators.pop());
                    logger->info("Moved operator to output");
                }
            }
            operators.push(token);
            logger->info("Pushed operator {} to stack", token);
        } else if (token == "(") {
            operators.push(token);
            logger->info("Pushed ( to stack");
        } else if (token == ")") {
            while (!operators.is_empty() && operators.peek() != "(") {
                if (!operators.is_empty()) {
                    output.push_back(operators.pop());
                    logger->info("Moved operator to output");
                }
            }
            if (!operators.is_empty()) {
                operators.pop(); // Discard the "("
                logger->info("Popped ( from stack");
            }
        }
    }

    // Empty remaining operators
    while (!operators.is_empty()) {
        output.push_back(operators.pop());
        logger->info("Moved remaining operator to output");
    }

    return output;
}
bool reader::postfix_notation_translator::is_math_action(const std::string& a) {
    return (a == "+" || a == "-" || a == "*" || a == "/" || a == "^");
}

bool reader::postfix_notation_translator::is_number(const std::string& token) {
    return !token.empty() && std::all_of(token.begin(), token.end(), ::isdigit);
}