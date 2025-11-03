#include <iostream>
#include <string>

using namespace std;

class Computer
{
public:
    virtual string description() const = 0;
    virtual double price() const = 0;
    virtual ~Computer() = default;
};

class Desktop : public Computer
{
public:
    string description() const override
    {
        return "Desktop";
    }

    double price() const override
    {
        return 1000.0;
    }
};

class Laptop : public Computer
{
public:
    string description() const override
    {
        return "Laptop";
    }

    double price() const override
    {
        return 1500.0;
    }
};

class ComputerDecorator : public Computer
{
    public:
        explicit ComputerDecorator(Computer* computer) : m_Computer(computer) {};

        string description() const override{
            return m_Computer->description();
        }

        double price() const override{
            return m_Computer->price(); 
        }
    protected:
        const Computer* m_Computer;
};

class MemoryUpgradeDecorator : public ComputerDecorator
{
public:
    explicit MemoryUpgradeDecorator(Computer *computer) : ComputerDecorator(computer) {}

    string description() const override
    {
        return ComputerDecorator::description() + " with memory upgrade";
    }

    double price() const override
    {
        return ComputerDecorator::price() + 500.0;
    }
};

class GraphicsUpgradeDecorator : public ComputerDecorator
{
public:
    explicit GraphicsUpgradeDecorator(Computer *computer) : ComputerDecorator(computer) {}

    string description() const override
    {
        return ComputerDecorator::description() + " with graphics upgrade";
    }

    double price() const override
    {
        return ComputerDecorator::price() + 500.0;
    }
};

int main()
{
    Computer *desktop = new Desktop();
    cout << desktop->description() << " costs $" << desktop->price() << endl;
    Computer *desktop1 = new MemoryUpgradeDecorator(desktop);
    cout << desktop1->description() << " costs $" << desktop1->price() << endl;
    Computer *laptop = new Laptop();
    cout << laptop->description() << " costs $" << laptop->price() << endl;

    // Computer *desktopGraphicsUpgrade = new DesktopWithGraphicsUpgrade();
    // cout << desktopGraphicsUpgrade->description() << " costs $" << desktopGraphicsUpgrade->price() << endl;

    // Computer *desktopMemoryUpgrade = new DesktopWithMemoryUpgrade();
    // cout << desktopMemoryUpgrade->description() << " costs $" << desktopMemoryUpgrade->price() << endl;

    // Computer *laptopGraphicsUpgrade = new LaptopWithGraphicsUpgrade();
    // cout << laptopGraphicsUpgrade->description() << " costs $" << laptopGraphicsUpgrade->price() << endl;

    // Computer *laptopMemoryUpgrade = new LaptopWithMemoryUpgrade();
    // cout << laptopMemoryUpgrade->description() << " costs $" << laptopMemoryUpgrade->price() << endl;

    // delete desktop;
    // delete laptop;
    // delete desktopGraphicsUpgrade;
    // delete desktopMemoryUpgrade;
    // delete laptopGraphicsUpgrade;
    // delete laptopMemoryUpgrade;

    return 0;
}
