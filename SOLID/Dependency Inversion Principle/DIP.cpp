#include <iostream>
#include <vector>
#include <memory>

using namespace std;

    /** 
    * Here i show a simple example how to follow dependency inversion principle (in Car_Service class)
    */

class Car;

class ICarService
{
public:
    virtual void Process(const Car& car) = 0;
    virtual ~ICarService() {};
};


class Car {
private:
    string model;
    string VIN;
public:
    Car(string model, string vin) : model(model), VIN(vin) {}

    string getModel() const { return model; }
    string getCarVIN() const { return VIN; }
};


// Low-level module: Concrete implementation of a service
class CarWashService: public ICarService
{
private:
    string serviceName;
public:
    CarWashService(string name) : serviceName(name) {}
        
    void Process(const Car& car) override {
        cout << "Washing " << car.getModel() << " [ " << car.getCarVIN() << " ]"<< " at " << serviceName << " service." << endl;
    }
};

// Low-level module: 
class CarEngineService: public ICarService
{
private:
    string serviceName;
public:
    CarEngineService(string name) : serviceName(name) {}
        
    void Process(const Car& car) override {
        cout << "Changing oil for " << car.getModel() << " [ " << car.getCarVIN() << " ]"<< " at " << serviceName << " service." << endl;
    }
};


// --- High-level class that does NOT depend on specific implementations ---
class CarServiceManager {
private:
    vector<shared_ptr<ICarService>> services;
public:
    void addService(shared_ptr<ICarService> service) {
        services.push_back(service);
    }

    void processAll(const Car& car) {
        for (auto& service : services) {
            service->Process(car);
        }
    }
};



int main() {  

    vector<Car> Car_park = { {"BMW M5 F10", "3GYFK62817G278819"}, 
                             {"BMW M5 G90", "JHMWD5523DS022721"}, 
                             {"BMW M5 G99", "ZFFEW58A660144998"}
                            };
    
    CarServiceManager manager;
    

    manager.addService(make_shared<CarWashService>("Clear Car"));
    manager.addService(make_shared<CarEngineService>("BMW Official Service"));

    
    manager.processAll(Car_park[0]);
    return 0;
}