#include <iostream>
#include <string>

class LogHandler {
public:
    static const std::string ERROR;
    static const std::string DEBUG;
    static const std::string INFO;

    LogHandler(LogHandler* handler) : nextHandler(handler) {}

    virtual void log(const std::string& type, const std::string& message) {
        if (nextHandler != nullptr)
            nextHandler->log(type, message);
    }

private:
    LogHandler* nextHandler;
};

class ErrorLogHandler : public LogHandler {
public:
    ErrorLogHandler(LogHandler* nextHandler) : LogHandler(nextHandler) {}

    void log(const std::string& type, const std::string& message) override {
        if (type == ERROR)
            std::cout << type << ": " << message << std::endl;
        else
            LogHandler::log(type, message);
    }
};

class DebugLogHandler : public LogHandler {
public:
    DebugLogHandler(LogHandler* nextHandler) : LogHandler(nextHandler) {}

    void log(const std::string& type, const std::string& message) override {
        if (type == DEBUG)
            std::cout << type << ": " << message << std::endl;
        else
            LogHandler::log(type, message);
    }
};

class InfoLogHandler : public LogHandler {
public:
    InfoLogHandler(LogHandler* nextHandler) : LogHandler(nextHandler) {}

    void log(const std::string& type, const std::string& message) override {
        if (type == INFO)
            std::cout << type << ": " << message << std::endl;
        else
            LogHandler::log(type, message);
    }
};

const std::string LogHandler::ERROR = "error";
const std::string LogHandler::DEBUG = "debug";
const std::string LogHandler::INFO = "info";

int main() {
    LogHandler* LOG = new InfoLogHandler(new ErrorLogHandler(new DebugLogHandler(nullptr)));

    LOG->log(LogHandler::ERROR, "error occurred");
    LOG->log(LogHandler::INFO, "Hi, this is handler pattern");
    LOG->log(LogHandler::DEBUG, "debugging the chain of responsibility");

    delete LOG; // Don't forget to release memory
    
    return 0;
}