#include <iostream>
#include <fstream>
#include <string>

class FileManager {
public:
    void readFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            while (getline(file, line)) {
                std::cout << line << std::endl;
            }
            file.close();
        } else {
            std::cerr << "Unable to open file for reading" << std::endl;
        }
    }

    void writeFile(const std::string& filename, const std::string& content) {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << content;
            file.close();
        } else {
            std::cerr << "Unable to open file for writing" << std::endl;
        }
    }

    void performFileOperation(const std::string& filename, const std::string& content) {
        writeFile(filename, content);
        readFile(filename);
    }
};

int main() {
    FileManager fileManager;
    std::string filename = "testfile.txt";
    std::string content = "Hello, world! This is a test.";

    fileManager.performFileOperation(filename, content);

    return 0;
}