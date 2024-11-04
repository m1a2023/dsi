#ifndef IDATASTRUCTURE_H
#define IDATASTRUCTURE_H

#include <iostream>
#include <functional>
#include <chrono>
#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace dsi {
template <typename T>
class TimeMeasurer : public IDataStructure<T> {
public:
    // Constructor and destructor
    TimeMeasurer(IDataStructure<T>* data_structure);
    ~TimeMeasurer();

    long double                 in_general();
    std::vector<long double>    in_vector();

    T                   pop();
    T                   peek();

    void                push(T item);

    int                 size();
    void                clear();
    bool                is_empty();

    std::string         to_string();

private:
    IDataStructure<T>                           *data_structure;
    
    std::shared_ptr<spdlog::logger>             logger;

    std::vector<std::chrono::duration<double>>  times; 
};
}

template <typename T>
dsi::TimeMeasurer<T>::TimeMeasurer(IDataStructure<T>* data_structure) {
    this->data_structure = data_structure;
    this->logger = spdlog::basic_logger_mt("time_measurer", "logs/time-measurer-logs.txt");
    this->logger->info("new data structure created: {}", typeid(data_structure).name());
}

template <typename T>
dsi::TimeMeasurer<T>::~TimeMeasurer() { }

template <typename T>
long double dsi::TimeMeasurer<T>::in_general() {
    long double res{ };

    for (auto p = this->times.begin(); p != this->times.end(); p++) {
        res += (*p).count();
    }

    this->logger->info("time in general: {}", res);

    return res;
}

template <typename T>
std::vector<long double> 
dsi::TimeMeasurer<T>::in_vector() {
    std::vector<long double> vec;

    for (auto p = this->times.begin(); p != this->times.end(); p++) {
        vec.push_back((*p).count());
    }

    return vec;
}

template <typename T>
T dsi::TimeMeasurer<T>::pop() {
    auto s = std::chrono::high_resolution_clock::now();
    T val = this->data_structure->pop();
    auto e = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration(e - s);
    this->times.push_back(duration);
    this->logger->info("poped with {}", duration.count());
    return val;
}

template <typename T>
T dsi::TimeMeasurer<T>::peek() {
    auto s = std::chrono::high_resolution_clock::now();
    T val = this->data_structure->peek();
    auto e = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration(e - s);
    this->times.push_back(duration);
    this->logger->info("peeked with {} time", duration.count());
    return val;
}

template <typename T>
void dsi::TimeMeasurer<T>::push(T item) {
    auto s = std::chrono::high_resolution_clock::now();
    this->data_structure->push(item);
    auto e = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration(e - s);
    this->times.push_back(duration);
    this->logger->info("pushed with {} time", duration.count());
    return;
}

template <typename T>
int dsi::TimeMeasurer<T>::size() {
    auto s = std::chrono::high_resolution_clock::now();
    int val = this->data_structure->size();
    auto e = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration(e - s);
    this->times.push_back(duration);
    this->logger->info("sized with {} time", duration.count());
    return val;
}

template <typename T>
void dsi::TimeMeasurer<T>::clear() {
    auto s = std::chrono::high_resolution_clock::now();
    this->data_structure->clear();
    auto e = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration(e - s);
    this->times.push_back(duration);
    this->logger->info("cleared with {} time", duration.count());
    return;
}

template <typename T>
bool dsi::TimeMeasurer<T>::is_empty() {
    auto s = std::chrono::high_resolution_clock::now();
    bool val = this->data_structure->is_empty();
    auto e = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration(e - s);
    this->times.push_back(duration);
    this->logger->info("is_empty with {} time", duration.count());
    return val;
}

template <typename T>
std::string dsi::TimeMeasurer<T>::to_string() {
    auto s = std::chrono::high_resolution_clock::now();
    std::string val = this->data_structure->to_string();
    auto e = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration(e - s);
    this->times.push_back(duration);
    this->logger->info("to_string with {} time", duration.count());
    return val;
}

#endif