#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <vector>

namespace reader {
    class postfix_notation_translator {

    public:
        static postfix_notation_translator in_vector(const std::vector<std::string>& vec);
        static std::vector<std::string> get();

    private:
        static std::vector<std::string> vec;
        static std::shared_ptr<spdlog::logger> logger;

        postfix_notation_translator();
        
        static std::vector<std::string> handle_data();   
        static bool is_math_action(const std::string& a);
        static bool is_number(const std::string& token);
    };
}
