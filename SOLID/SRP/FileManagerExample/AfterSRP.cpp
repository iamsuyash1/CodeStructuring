#include <iostream>
#include <fstream>
#include <string>

/*
    In this example, we have implemented a basic file management system with SRP in mind. 
    We have created classes for handling different responsibilities:

    FileReader: Reads data from a file.
    FileWriter: Writes data to a file.
    FileManager: Manages file operations and utilizes FileReader and FileWriter.

*/

class FileReader {
public:
    std::string read(const std::string& filename) {
        std::ifstream file(filename);
        std::string content;
        if (file.is_open()) {
            std::string line;
            while (getline(file, line)) {
                content += line + "\n";
            }
            file.close();
        } else {
            std::cerr << "Unable to open file for reading" << std::endl;
        }
        return content;
    }
};

class FileWriter {
public:
    void write(const std::string& filename, const std::string& content) {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << content;
            file.close();
        } else {
            std::cerr << "Unable to open file for writing" << std::endl;
        }
    }
};

class FileManager {
private:
    FileReader fileReader;
    FileWriter fileWriter;

public:
    void performFileOperation(const std::string& filename, const std::string& content) {
        fileWriter.write(filename, content);
        std::string fileContent = fileReader.read(filename);
        std::cout << "File content after writing and reading:\n" << fileContent << std::endl;
    }
};

int main() {
    FileManager fileManager;
    std::string filename = "testfile.txt";
    std::string content = "Hello, world! This is a test.";

    fileManager.performFileOperation(filename, content);

    return 0;
}