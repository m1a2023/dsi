#include "../headers/PostfixNotationTranslator.h"
//#include "../headers/Stack.h"
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
    std::stack<std::string> operators; 

    std::unordered_map<std::string, int> precedence {
        {"+", 1}, {"-", 1},
        {"*", 2}, {"/", 2}, 
        {"sin", 3}, {"cos", 3}, {"sqrt", 3}, {"ln", 3},
        {"^", 4}
    };

    std::unordered_map<std::string, bool> right_associative {
        {"^", true}
    };
    
    for (const auto& token : vec) {
        if (is_number(token)) {
            output.push_back(token);
        } else if (is_math_action(token)) {
            if (is_unary_function(token)) {
                operators.push(token);
            } else {
                while (!operators.empty() &&
                       (precedence[operators.top()] > precedence[token] || 
                        (precedence[operators.top()] == precedence[token] && !right_associative[token]))) {
                    output.push_back(operators.top());
                    operators.pop();
                }
                operators.push(token);
            }
        } else if (token == "(") {
            operators.push(token);
        } else if (token == ")") {
            while (!operators.empty() && operators.top() != "(") {
                output.push_back(operators.top());
                operators.pop();
            }
            if (!operators.empty()) {
                operators.pop(); // pop the '('
            }
            if (!operators.empty() && is_unary_function(operators.top())) {
                output.push_back(operators.top());
                operators.pop();
            }
        }
    }

    while (!operators.empty()) {
        output.push_back(operators.top());
        operators.pop();
    }

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