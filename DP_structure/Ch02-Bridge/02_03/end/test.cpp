#include <iostream>
#include <memory>

class IEngine
{
    public:
        virtual void start() const = 0;
        virtual ~IEngine() = default;
};

class IVehicle
{
    public:
        explicit IVehicle(IEngine &IEngine) : iEngine(IEngine) {}; 
        virtual void drive() = 0;
        virtual void driveVehcile(){
            iEngine.start();
        }
    protected:
        IEngine &iEngine;       
};

class Car : public IVehicle
{
    public:
        explicit Car(IEngine &IEngine) : IVehicle(IEngine) {}; 
        void drive() override{
            std::cout << "Drive a car\n";
        }  
};


class Truck : public IVehicle
{
    public:
        explicit Truck(IEngine &IEngine) : IVehicle(IEngine) {}; 
 
    void drive() override{
            std::cout << "Drive a truck\n";
        }
};

class GasEngine : public IEngine
{
    public:
        void start() const override{
            std::cout << "GasEngine" << std::endl;
        }
};

class ElecEngine : public IEngine
{
    public:
        void start() const override{
            std::cout << "ElecEngine" << std::endl;
        }
};

int main()
{
    ElecEngine elecEngine;
    std::unique_ptr<IVehicle> vehicle[]
    {
        std::make_unique<Truck>(elecEngine)
    };

    vehicle[0]->drive();
    vehicle[0]->driveVehcile();
}