#include <iostream>
#include <vector>
#include <memory>

using namespace std;

    /** 
    * Here i show a simple example how to follow open-close principle (in Car_Service class)
    * 
    * The open-closed principle states that software entities (classes, modules, functions, and so on) 
    * should be open for extension, but closed for modification.
    * 
    * It means we should be able to add new functionalities to an existing software system 
    * without changing the existing code.
    * 
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


class CarService {
private:
    string serviceName;
public:
    CarService(string name) : serviceName(name) {}
    
    virtual void Process(const Car&) = 0; 
    
    string GetServiceName() const { return serviceName; } 
    virtual ~CarService() = default;
};

class ChangeOil : public CarService
{
public:
    ChangeOil(string name) : CarService(name) {} 

    void Process(const Car& car) override {
        cout << "Changing oil for " << car.getModel() << " [" << car.getCarVIN() 
             << "] at " << GetServiceName() << " service." << endl;
    }
};

class RepairEngine : public CarService {
public:
    RepairEngine(string name) : CarService(name) {}
    
    void Process(const Car& car) override {
        cout << "Repairing engine for " << car.getModel() << " [" << car.getCarVIN() 
            << "] at " << GetServiceName() << " service." << endl;
    }
};
    
 
class Wash : public CarService {
public:
    Wash(string name) : CarService(name) {}
    
    void Process(const Car& car) override {
        cout << "Washing " << car.getModel() << " [" << car.getCarVIN() 
            << "] at " << GetServiceName() << " service." << endl;
    }
};

/**
 * In this architecture (Open-Close principle) we can add new features, just add a new class that will implement the feature
 */

int main() {  

    vector<Car> Car_park = { {"BMW M5 F10", "3GYFK62817G278819"}, 
                             {"BMW M5 G90", "JHMWD5523DS022721"}, 
                             {"BMW M5 G99", "ZFFEW58A660144998"}
                            };
    

      
    vector<CarService*> Services;

       
    Services.push_back(new ChangeOil("Oil Change Service"));
    Services.push_back(new RepairEngine("Engine Repair Service"));
    Services.push_back(new Wash("Premium Car Wash"));
    
    
    int index = 0;

    for(const auto& item: Services)
    {
        item->Process(Car_park[index]);
        index++;
    }

    for(auto &item: Services)
        delete item;

    return 0;
}