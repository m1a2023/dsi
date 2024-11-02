#include "../headers/PostfixNotationTranslator.h"

std::vector<std::string> reader::postfix_notation_translator::vec;
std::shared_ptr<spdlog::logger> reader::postfix_notation_translator::logger = nullptr;

reader::postfix_notation_translator::postfix_notation_translator() {
    if (!logger) {
        logger = spdlog::basic_logger_mt("postfix_notation_translator", "logs/postfix-notation-translator.txt");
    }
    else {
        std::cout << "u r dumb" << std::endl;
    }
}

reader::postfix_notation_translator 
reader::postfix_notation_translator::in_vector(const std::vector<std::string>& vec) {
    postfix_notation_translator::vec = vec;
    postfix_notation_translator instance;
    postfix_notation_translator::logger->info("added (/vector/)");
    return instance;
}

std::vector<std::string>
reader::postfix_notation_translator::get() {
    postfix_notation_translator::logger->info("get(/vector/)");
    return postfix_notation_translator::handle_data();
}

std::vector<std::string> 
reader::postfix_notation_translator::handle_data() {

    for(auto p = postfix_notation_translator::vec.begin();
        p != postfix_notation_translator::vec.end(); p++) 
    {
        postfix_notation_translator::logger->info("element");

        auto next = std::next(p);
        if (next != postfix_notation_translator::vec.end() && is_math_action(*p)) {
            std::iter_swap(p, next);
            
            postfix_notation_translator::logger->info("swaped elements");

            p++;
        }
    }

    return reader::postfix_notation_translator::vec;
} 

bool 
reader::postfix_notation_translator::is_math_action(const std::string& a) {
    return (a == "+" || a == "-" || a == "*" || a == "/" || a == "ln" || 
            a == "^" || a == "cos" || a == "sin" || a == "sqrt");
}