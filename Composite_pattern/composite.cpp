#include <iostream>
#include <vector>
#include <string>

// Forward declaration
class FileSystem;

class Directory {
private:
    std::string directoryName;
    std::vector<FileSystem*> files;

public:
    Directory(const std::string& directoryName) : directoryName(directoryName) {}

    void addFile(FileSystem* file) {
        files.push_back(file);
    }

    void ls() {
        std::cout << "d-" << directoryName << std::endl;
        for (FileSystem* file : files) {
            file->ls();
        }
    }
};

class File : public FileSystem {
private:
    std::string filename;

public:
    File(const std::string& fileName) : filename(fileName) {}

    void ls() override {
        std::cout << "f-" << filename << std::endl;
    }
};

class FileSystem {
public:
    virtual void ls() = 0;
};

int main() {
    // create Directory Composite Design Pattern
    Directory compositeDesignPatternDirectory("composite-design-pattern");

    // create one directory filesystem in composite design pattern
    Directory fileSystem("file-system");

    compositeDesignPatternDirectory.addFile(&FileSystem);

    // create file and add it to the file system directory
    File client("Client.java");
    fileSystem.addFile(&client);

    // create another file and add it to composite design pattern directory
    File readMe("README.md");
    compositeDesignPatternDirectory.addFile(&readMe);

    // ls composite design pattern directory
    compositeDesignPatternDirectory.ls();

    // ls file system directory
    fileSystem.ls();

    return 0;
}