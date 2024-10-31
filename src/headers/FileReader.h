#include "LinkedList.h"

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace dsi {
    template <typename T> class FileReader{
    public:
        FileReader(const std::string& filename);
        ~FileReader();

        void process_file(IDataStructure<T>* structure);

        /**
         * TODO add method that will get absolute path to this directory 
         * and put it in filename to get correct path
         * 
         * OR
         * 
         * TODO use another way getting the path 
         */
    private:
        LinkedList<T>* list;

        /**
         * ! use only RELATIVE PATH
         */
        std::string filename;

        /**
         * use logger for output and report
         */

        // TODO Logger
        std::shared_ptr<spdlog::logger> file_reader_logger;
    };

    template <typename T>
    FileReader<T>::FileReader(const std::string& filename) : filename(filename) {
        this->file_reader_logger = spdlog::basic_logger_mt("file_reader_logger", "logs/file-reader-logs.txt");
        this->file_reader_logger->info("New FileReader was created");
        this->list = new LinkedList<T>();
    }

    template <typename T>
    FileReader<T>::~FileReader() {
        this->file_reader_logger->info("FileReader was deallocated");
        this->list->clear();
        delete this->list;
    }

    template <typename T>
    void FileReader<T>::process_file(IDataStructure<T>* structure) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            this->file_reader_logger->error("Error while opening the file");
            //std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string command;

            while (iss >> command) {
                if (command[0] == '1') {
                    std::string value = command.substr(2);  
                    structure->push(value);

                    this->file_reader_logger->info("command: push, value: {0}", value);
                    //std::cout << "Pushed: " << value << std::endl;
                }
                else if (command == "2") {
                    try {
                        T popped = structure->pop();
                        this->file_reader_logger->info("command: pop, value: {0}", popped);
                        //std::cout << "Popped: " << popped << std::endl;
                    }
                    catch (const std::exception& e) {
                        this->file_reader_logger->error("Error while popping the value: stack is empty");
                        std::cerr << e.what() << std::endl;
                    }
                }
                else if (command == "3") {
                    try {
                        T top = structure->peek();
                        this->file_reader_logger->info("command: peek, value: {0}", top);
                        //std::cout << "Top: " << top << std::endl;
                    }
                    catch (const std::exception& e) {
                        this->file_reader_logger->error("Error while peeking the value: stack is empty");
                        //std::cerr << e.what() << std::endl;
                    }
                }
                else if (command == "4") {
                    bool empty = structure->is_empty();
                    this->file_reader_logger->info("command: is_empty?, value: {0}", (empty ? "Yes" : "No"));
                    //std::cout << "IsEmpty: " << (empty ? "Yes" : "No") << std::endl;
                }
                else if (command == "5") {
                    this->file_reader_logger->info("command: to_string, value: {0}", structure->to_string());
                    //std::cout << "Structure: " << structure->to_string() << std::endl;
                }
            }
        }

        file.close();
    }
}