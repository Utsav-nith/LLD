#include <iostream>
#include <string>

class XML {
public:
    virtual std::string getXml() = 0;
};

class XMLImpl : public XML {
public:
    std::string getXml() override {
        std::cout << "xml : <>" << std::endl;
        return "<>";
    }
};

class Adapter {
public:
    virtual std::string convert() = 0;
};

class JSONAdapter : public Adapter {
    XML* xml;

public:
    JSONAdapter(XML* xml) : xml(xml) {}

    std::string convert() override {
        std::string xmlData = xml->getXml();
        // Convert xml to json
        std::cout << "converting to json : {}" << std::endl;
        std::string jsonData = xmlData;
        // Replace XML-specific parts with JSON-specific ones
        jsonData.replace(jsonData.find("<>"), 2, "{}");
        return jsonData;
    }
};

int main() {
    XML* xmlImpl = new XMLImpl();
    Adapter* adapter = new JSONAdapter(xmlImpl);

    std::cout << "Result : " << adapter->convert() << std::endl;

    delete adapter;
    delete xmlImpl;

    return 0;
}