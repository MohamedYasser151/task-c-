
#include<iostream>
#include<string>

class PassengerDetails {
protected:
    int noOfPassengers;
    int amountOfCargoes;

public:
    PassengerDetails(int passengers, int cargoes) : noOfPassengers(passengers), amountOfCargoes(cargoes) {}

    virtual void travelCost() = 0;
};

class Airplane : public PassengerDetails {
private:
    std::string typeOfEngine;
    int rangeInMiles;

public:
    Airplane(std::string engine, int passengers, int cargoes, int range) : PassengerDetails(passengers, cargoes), typeOfEngine(engine), rangeInMiles(range) {}

    void travelCost() override {
        if(typeOfEngine == "propeller") {
            std::cout << "Cost: " << (5000 * rangeInMiles) << std::endl;
        } else if(typeOfEngine == "jet") {
            std::cout << "Cost: " << (6000 * rangeInMiles) << std::endl;
        }
    }

    void displayDetails() {
        std::cout << "Type of engine: " << typeOfEngine << std::endl;
        std::cout << "Range in miles: " << rangeInMiles << std::endl;
    }
};

int main() {
    Airplane airplane1("propeller", 50, 2000, 600);
    airplane1.displayDetails();
    airplane1.travelCost();

    Airplane airplane2("jet", 100, 4000, 600);
    airplane2.displayDetails();
    airplane2.travelCost();

    return 0;
}