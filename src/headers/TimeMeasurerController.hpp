#pragma once

#include <string>
#include <iostream>
#include <tuple>
#include <fstream>
#include <memory>
#include <iomanip>

#include <IDataStructure.h>
#include <InnerQueue.hpp>
#include <InnerStack.hpp>
#include <Queue.h>
#include <Stack.h>
#include <TimeMeasurer.h>
#include <vector>

#include <spdlog/fmt/ranges.h>

namespace dsi {
template <typename T>
class _time_measurer_controller {

public:

    _time_measurer_controller(const std::vector<std::shared_ptr<TimeMeasurer<T>>> measurers);
    ~_time_measurer_controller();

    void to_file(const std::string &filepath);
    
    void    pop();
    void    peek();

    void    push(T item);

private:  

    std::vector<std::shared_ptr<TimeMeasurer<T>>> measurers;   
};
}

template <typename T>
dsi::_time_measurer_controller<T>::_time_measurer_controller(const std::vector<std::shared_ptr<TimeMeasurer<T>>> measurers) {
    this->measurers = measurers;
}

template <typename T>
dsi::_time_measurer_controller<T>::~_time_measurer_controller() { }

template <typename T>
void dsi::_time_measurer_controller<T>::to_file(const std::string &filepath) {
    std::ofstream stream(filepath, std::ios::out | std::ios::trunc);

    if (!stream) {
        throw std::ios_base::failure("Failed to open file: " + filepath);
    }

    std::string line_buffer;
    line_buffer.reserve(1024);

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(12); 

    for (const auto& measurer : this->measurers) {
        const auto& data = measurer->in_vector();
        line_buffer.clear();

        for (const auto& value : data) {
            oss.str("");
            oss.clear();
            
            oss << value;
            
            line_buffer += oss.str() + ' ';
        }

        if (!line_buffer.empty()) {
            line_buffer.back() = '\n';
        }
        
        stream << line_buffer;
    }
}

template <typename T> void 
dsi::_time_measurer_controller<T>::pop() {
    for (auto measurer : this->measurers) {
        measurer->pop();
    }
}

template <typename T> void 
dsi::_time_measurer_controller<T>::peek() {
    for (auto measurer : this->measurers) {
        measurer->peek();
    }
}

template <typename T> void 
dsi::_time_measurer_controller<T>::push(T item) {
    for (auto measurer : this->measurers) {
        measurer->push(item);
    }
}