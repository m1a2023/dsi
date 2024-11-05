#ifndef STACK_H
#define STACK_H

#include <cmath>
#include <string>
#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <vector>
#include <functional>
#include <exception>
#include <stdexcept>

namespace dsi { 
template <typename T>
class stack_calc {
public:
    static T calculate(const std::vector<std::string>& vec);

private: 
    stack_calc() = delete;

    static bool is_num(const std::string& s);
    static bool is_unary_function(const std::string& s);
    static bool is_math_action(const std::string& s);
    static std::function<T(T, T)> get_bin_action(const std::string& s);
    static std::function<T(T)> get_unary_action(const std::string& s);

    static dsi::Stack<T> stack;
    static std::shared_ptr<spdlog::logger> logger;
};

}


template <typename T>
dsi::Stack<T> dsi::stack_calc<T>::stack;

template <typename T>
std::shared_ptr<spdlog::logger> dsi::stack_calc<T>::logger = spdlog::basic_logger_mt("stack_calculation", "logs/stack-calc-logs.txt");//spdlog::get("stack_calc") 

template <typename T>
T dsi::stack_calc<T>::calculate(const std::vector<std::string>& vec) {
    
    for (auto p = vec.begin(); p != vec.end(); p++) {
        if (is_num(*p)) stack_calc::stack.push(static_cast<T> (std::stoi(*p)));
        else if (is_unary_function(*p)) {
            T a = stack.pop();
            auto fun = get_unary_action(*p);
            stack.push(fun(a));      
            stack_calc<T>::logger->info("fun: {}, val: {}", *p, a);
        } else {
            T a = stack.pop();
            T b = stack.pop();
            auto fun = get_bin_action(*p);
            stack.push(fun(b, a));
            stack_calc<T>::logger->info("fun: {}, vals: {}, {}", *p, b, a);
        }
    }
    
    stack_calc<T>::logger->info("result: {}", stack.peek());
    return stack.pop();
}

template <typename T>
bool dsi::stack_calc<T>::is_num(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;

    return !s.empty() && it == s.end();
}

template <typename T>
std::function<T(T, T)> dsi::stack_calc<T>::get_bin_action(const std::string& s) {
    if (s == "+") return [](T a, T b) { return a + b; };
    if (s == "-") return [](T a, T b) { return a - b; };
    if (s == "*") return [](T a, T b) { return a * b; };
    if (s == "/") return [](T a, T b) { if (b == 0) throw std::runtime_error("Division by zero"); return a / b; };
    if (s == "^") return [](T a, T b) { return std::pow(a, b); };
    else throw std::invalid_argument("e: " + s);
}

template <typename T>
std::function<T(T)> dsi::stack_calc<T>::get_unary_action(const std::string& s) {
    if (s == "sin") return [](T a) { return std::sin(a); };
    if (s == "cos") return [](T a) { return std::cos(a); };
    if (s == "sqrt") return [](T a) { return std::sqrt(a); };
    if (s == "ln") return [](T a) { return std::log(a); };
    else throw std::invalid_argument("e: " + s);
}

template <typename T>
bool dsi::stack_calc<T>::is_unary_function(const std::string& token) {
    return (token == "cos" || token == "sin" || token == "sqrt" || token == "ln");
}

template <typename T>
bool dsi::stack_calc<T>::is_math_action(const std::string& a) {
    return (a == "+" || a == "-" || a == "*" || a == "/" || a == "^" || 
            a == "cos" || a == "sin" || a == "sqrt" || a == "ln");
}

#endif