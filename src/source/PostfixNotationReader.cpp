#ifndef POSTFIXNOTATIONREADER
#define POSTFIXNOTATIONREADER
#include "../headers/PostfixNotationReader.h"

std::string reader::postfix_notation_reader::file;
std::string reader::postfix_notation_reader::data;
std::shared_ptr<spdlog::logger> reader::postfix_notation_reader::logger = nullptr;

reader::postfix_notation_reader::postfix_notation_reader() {
    if (!logger) {
        logger = spdlog::basic_logger_mt("postfix_logger", "logs/postfix_notation_reader-logs.txt");
    }
}

reader::postfix_notation_reader 
reader::postfix_notation_reader::in_file(const std::string& file_name) {
    postfix_notation_reader::file = file_name;
    postfix_notation_reader reader;

    std::ifstream f(file_name);
    if (!f.is_open()) {
        postfix_notation_reader::logger->error("Error while opening the file: {}", file_name);
        return reader;
    }

    logger->info("postfix_notation_reader::file = {}", file_name);
    std::string tmp_data;

    while (std::getline(f, tmp_data)) {
        postfix_notation_reader::data.append(tmp_data + " ");
        logger->info("postfix_notation_reader::data.append({})", tmp_data);
    }

    f.close();
    return reader;
}

std::vector<std::string> reader::postfix_notation_reader::get() {
    return postfix_notation_reader::handle_data();
}

std::vector<std::string> reader::postfix_notation_reader::handle_data() {
    std::vector<std::string> l;
    std::istringstream s(postfix_notation_reader::data);
    std::string tmp_data;

    postfix_notation_reader::logger->info("splitting string...");

    while (std::getline(s, tmp_data, ' ')) {
        l.push_back(tmp_data);
        postfix_notation_reader::logger->info("added {} to verctor", tmp_data);
    }

    return l;
}
#endif