#include <iostream>
#include <vector>

using namespace std;

    /** 
    * Here i show a simple example how to follow single responsibility principle (in Car_Service class)
    */
   
class Car {
private:
    string model;
    string VIN;
public:
    Car(string model, string vin) : model(model), VIN(vin) {}

    string getModel() const { return model; }
    string getCarVIN() const { return VIN; }
};

// A CarService deals only with repairs and maintenance
class CarService {
private:
    string serviceName;
public:
    CarService(string name) : serviceName(name) {}

    void changeOil(const Car& car) {
        cout << "Changing oil for " << car.getModel() << " [ " << car.getCarVIN() << " ]"<< " at " << serviceName << " service." << endl;
    }

    void repairEngine(const Car& car) {
        cout << "Changing oil for " << car.getModel() << " [ " << car.getCarVIN() << " ]"<< " at " << serviceName << " service." << endl;
    }

    // Washing car not responsibility of Service, including the option, we lose SRP principle
    /*
    void washCar(const Car& car) {
        cout << "Washing " << car.getModel() << " [ " << car.getCarVIN() << " ]"<< " at " << serviceName << " service." << endl;
    }
    */
};

/*For solve the problem/situation with responsibilities we should to shift the responsibility of washing car */

class CarWashService 
{
    private:
        string serviceName;
    public:
    CarWashService(string name) : serviceName(name) {}
        void washCar(const Car& car) {
            cout << "Washing " << car.getModel() << " [ " << car.getCarVIN() << " ]"<< " at " << serviceName << " service." << endl;
        }
    };


int main() {  

    vector<Car> Car_park = { {"BMW M5 F10", "3GYFK62817G278819"}, 
                             {"BMW M5 G90", "JHMWD5523DS022721"}, 
                             {"BMW M5 G99", "ZFFEW58A660144998"}
                            };

    CarService service("BMW Official Service");

    service.changeOil(Car_park[2]);
    service.repairEngine(Car_park[0]);

    CarWashService car_wash("Wash Your Car");
    car_wash.washCar(Car_park[0]);

    return 0;
}