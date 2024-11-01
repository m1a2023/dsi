#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <vector>

namespace reader {


    class postfix_notation_reader 
    {
    public:
        static postfix_notation_reader in_file(const std::string file_name);
        static std::vector<std::string> get();
        
    private:
        postfix_notation_reader();

        static std::vector<std::string> handle_data(); 

        //static std::string file;
        //static std::string data;
        //static std::shared_ptr<spdlog::logger> logger;       
    };
}

