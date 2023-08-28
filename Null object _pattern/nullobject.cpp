#include <iostream>
#include <string>

class Vehicle {
public:
    virtual int getTankCapacity() = 0;
    virtual int getSeatCapacity() = 0;
};

class Bike : public Vehicle {
public:
    int getTankCapacity() override {
        return 3;
    }

    int getSeatCapacity() override {
        return 1;
    }
};

class Car : public Vehicle {
public:
    int getTankCapacity() override {
        return 13;
    }

    int getSeatCapacity() override {
        return 4;
    }
};

class NullObject : public Vehicle {
public:
    int getTankCapacity() override {
        return 0;
    }

    int getSeatCapacity() override {
        return 0;
    }
};

class VehicleFactory {
public:
    static Vehicle* getVehicle(const std::string& vehicle) {
        if (vehicle == "car") {
            return new Car();
        } else if (vehicle == "bike") {
            return new Bike();
        }

        return new NullObject();
    }
};

void printVehicleDetails(Vehicle* v) {
    std::cout << "Seat capacity: " << v->getSeatCapacity() << std::endl;
    std::cout << "Tank capacity: " << v->getTankCapacity() << std::endl;
}

int main() {
    Vehicle* car = VehicleFactory::getVehicle("car");
    printVehicleDetails(car);
    delete car;

    Vehicle* bike = VehicleFactory::getVehicle("bike");
    printVehicleDetails(bike);
    delete bike;

    Vehicle* truck = VehicleFactory::getVehicle("truck");
    printVehicleDetails(truck);
    delete truck;

    return 0;
}