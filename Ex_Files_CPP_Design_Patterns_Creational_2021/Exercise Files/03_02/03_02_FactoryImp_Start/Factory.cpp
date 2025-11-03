class Vehicle {                        // Abstraction (what is a Vehicle)
public:
    virtual void drive() = 0;          // Polymorphism (drive differently)
    virtual ~Vehicle() = default;
};

class Car : public Vehicle {           // Inheritance
public:
    void drive() override {            // Polymorphism (Car's way)
        std::cout << "Car driving fast\n";
    }
};

class Bike : public Vehicle {          // Inheritance
public:
    void drive() override {            // Polymorphism (Bike's way)
        std::cout << "Bike pedaling\n";
    }
};

class VehicleFactory {                 // Abstraction (what is a factory)
public:
    virtual Vehicle* createVehicle() = 0; // Polymorphic factory method
    virtual ~VehicleFactory() = default;
};

class CarFactory : public VehicleFactory { // Inheritance
public:
    Vehicle* createVehicle() override {    // Polymorphism (which Vehicle)
        // Encapsulation: creation details hidden here
        return new Car();
    }
};
