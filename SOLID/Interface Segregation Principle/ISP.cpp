#include <iostream>
#include <vector>
#include <memory>

using namespace std;

    /**
    * This example illustrates the Interface Segregation Principle (ISP).
    *
    * ISP states that clients should not be forced to depend on methods they do not use.
    * In the context of car services, this means splitting functionality into small,
    * specific interfaces such as IWashService, IOilChangeService, and IEngineRepairService.
    *
    * Each service class then implements only the interface(s) relevant to its functionality.
    * This promotes cleaner, more maintainable code and avoids bloated, general-purpose interfaces.
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

class IOilChangeService {
public:
    virtual void ChangeOilProcess(const Car&) = 0;
    virtual ~IOilChangeService() = default;
};
    
class IEngineRepairService {
public:
    virtual void RepairEngine(const Car&) = 0;
    virtual ~IEngineRepairService() = default;
};
    
class ICarWashService {
 public:
    virtual void WashCar(const Car&) = 0;
    virtual ~ICarWashService() = default;
};


class ChangeOil : public IOilChangeService {
private:
    string serviceName;
public:
    ChangeOil(string name) : serviceName(name) {}
    
    void ChangeOilProcess(const Car& car) override {
        cout << "Changing oil for " << car.getModel() << " [" << car.getCarVIN()
            << "] at " << serviceName << " service." << endl;
    }
};

class RepairEng: public IEngineRepairService
{
private:
    string serviceName;
public:

RepairEng(string name): serviceName(name) {}

    void RepairEngine(const Car& car) override{
        cout << "Repairing engine for " << car.getModel() << " [" << car.getCarVIN() 
        << "] at " << serviceName << " service." << endl;
    }
};

class Wash: public ICarWashService
{
private:
    string serviceName;
public:
    Wash(string name) : serviceName(name) {}

    void WashCar(const Car& car) override{
        cout << "Washing " << car.getModel() << " [" << car.getCarVIN() 
        << "] at " << serviceName << " service." << endl;
    }
};





int main() {  

    vector<Car> Car_park = { {"BMW M5 F10", "3GYFK62817G278819"}, 
                             {"BMW M5 G90", "JHMWD5523DS022721"}, 
                             {"BMW M5 G99", "ZFFEW58A660144998"}
                            };
    
     // Create service instances
     ChangeOil oilService("Oil Change Service");
     RepairEng repairService("Engine Repair Service");
     Wash washService("Premium Car Wash");

    oilService.ChangeOilProcess(Car_park[0]);
    repairService.RepairEngine(Car_park[1]);
    washService.WashCar(Car_park[2]);
    
    return 0;

}
