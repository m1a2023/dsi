#include "PostfixNotationReader.h"

using namespace reader;

namespace reader {
    static std::string file;
    static std::string data;
    static std::shared_ptr<spdlog::logger> logger;       

    postfix_notation_reader::postfix_notation_reader() {
        logger = spdlog::basic_logger_mt("postfix_notation_reader_logger", 
                                    "logs/postfix-notation-reader.txt", true);
    }

postfix_notation_reader 
postfix_notation_reader::in_file(const std::string file_name) {
    file = file_name;

    std::ifstream f(file_name);

    if (!f.is_open()) {
        logger->error("Error while opening the file: {0}", file_name);
        return postfix_notation_reader();
    }

    logger->info("postfix_notation_reader::file = {0}", file_name);
    std::string tmp_data;

    while (std::getline(f, tmp_data)) {
        data.append(tmp_data); 
        logger->info("postfix_notation_reader::data.append({0})", tmp_data);
    }

    f.close();

    return postfix_notation_reader();
}

std::vector<std::string> reader::postfix_notation_reader::get()
{
    return postfix_notation_reader::handle_data();
}

std::vector<std::string>
reader::postfix_notation_reader::handle_data()
{
    std::vector<std::string> l;

    std::istringstream s;
    std::string tmp_data;
    s.str(data);

    logger->info("splitting string...");

    while (std::getline(s, tmp_data, ' ')) {
        l.push_back(tmp_data);
        logger->info("added {0}", tmp_data);
    }

    return l;
}
}