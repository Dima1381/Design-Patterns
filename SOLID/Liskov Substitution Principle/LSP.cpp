#include <iostream>
#include <vector>
#include <memory>

using namespace std;

    /** 
    * Here i show a simple example how to follow LSP (in Car_Service class)
    * 
    * The Liskov Substitution Principle states that objects of a subclass should be substitutable
    * for objects of the base class without affecting the correctness of the program.
    * 
    * In this example, all services (ChangeOil, RepairEngine, Wash) inherit from the CarService base class,
    * and each properly overrides the Process() method. This allows us to use any service
    * through a pointer or reference to CarService without needing to know the exact derived type.
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
