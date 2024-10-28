#include "LinkedList.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

namespace dsi {
    template <typename T> class FileReader{
    public:
        // ����������� � ����������
        FileReader(const std::string& filename);
        ~FileReader();

        // �������� ������
        void process_file(IDataStructure<T>* structure);

    private:
        LinkedList<T>* list;
        std::string filename;
    };

    // �����������
    template <typename T>
    FileReader<T>::FileReader(const std::string& filename) : filename(filename) {
        this->list = new LinkedList<T>();
    }

    // ����������
    template <typename T>
    FileReader<T>::~FileReader() {
        this->list->clear();
        delete this->list;
    }

    template <typename T>
    void FileReader<T>::process_file(IDataStructure<T>* structure) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string command;

            // ��������� ������� �� ������
            while (iss >> command) {
                if (command[0] == '1') {
                    // �������� Push
                    std::string value = command.substr(2);  // �������� ����� �������
                    structure->push(value);
                    std::cout << "Pushed: " << value << std::endl;
                }
                else if (command == "2") {
                    // �������� Pop
                    try {
                        T popped = structure->pop();
                        std::cout << "Popped: " << popped << std::endl;
                    }
                    catch (const std::exception& e) {
                        std::cerr << e.what() << std::endl;
                    }
                }
                else if (command == "3") {
                    // �������� Top (��� Peek)
                    try {
                        T top = structure->peek();
                        std::cout << "Top: " << top << std::endl;
                    }
                    catch (const std::exception& e) {
                        std::cerr << e.what() << std::endl;
                    }
                }
                else if (command == "4") {
                    // �������� isEmpty
                    bool empty = structure->is_empty();
                    std::cout << "IsEmpty: " << (empty ? "Yes" : "No") << std::endl;
                }
                else if (command == "5") {
                    // �������� Print
                    std::cout << "Structure: " << structure->to_string() << std::endl;
                }
            }
        }

        file.close();
    }
}