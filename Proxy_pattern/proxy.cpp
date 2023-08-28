#include <iostream>
#include <string>

class EmployeeDao {
public:
    virtual void create(const std::string& client, EmployeeDao* employeeDao) = 0;
    virtual void get(const std::string& client) = 0;
    virtual void deleteEmployee(const std::string& client, EmployeeDao* employeeDao) = 0;
};

class EmployeeDaoImpl : public EmployeeDao {
public:
    void create(const std::string& client, EmployeeDao* employeeDao) override {
        std::cout << "employeedao created successfully" << std::endl;
    }

    void get(const std::string& client) override {
        std::cout << "get employee" << std::endl;
    }

    void deleteEmployee(const std::string& client, EmployeeDao* employeeDao) override {
        std::cout << "delete employee" << std::endl;
    }
};

class EmployeeDaoProxy : public EmployeeDao {
private:
    EmployeeDaoImpl employeeDaoImpl;

public:
    EmployeeDaoProxy() {
        // employeeDaoImpl = new EmployeeDaoImpl();  // No need for dynamic allocation in C++
    }

    void create(const std::string& client, EmployeeDao* employeeDao) override {
        if (client == "ADMIN") {
            employeeDaoImpl.create(client, employeeDao);
        } else {
            throw std::runtime_error("ACCESS-DENIED");
        }
    }

    void get(const std::string& client) override {
        if (client == "USER" || client == "ADMIN") {
            employeeDaoImpl.get(client);
        } else {
            throw std::runtime_error("ACCESS-DENIED");
        }
    }

    void deleteEmployee(const std::string& client, EmployeeDao* employeeDao) override {
        if (client == "ADMIN") {
            employeeDaoImpl.deleteEmployee(client, employeeDao);
        } else {
            throw std::runtime_error("ACCESS-DENIED");
        }
    }
};

int main() {
    EmployeeDaoProxy employeeDaoProxy;

    try {
        employeeDaoProxy.create("USER", &employeeDaoProxy);
        std::cout << "Success" << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}