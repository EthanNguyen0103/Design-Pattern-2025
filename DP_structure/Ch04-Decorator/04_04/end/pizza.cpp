#include <iostream>
#include <memory>
using namespace std;

class Pizza
{
public:
    virtual string description() const = 0;
    virtual double price() const = 0;
    virtual ~Pizza() = default;
};

class MargheritaPizza : public Pizza
{
public:
    string description() const override
    {
        return "Margherita Pizza";
    }

    double price() const override
    {
        return 9.99;
    }
};

class HawaiianPizza : public Pizza
{
public:
    string description() const override
    {
        return "Hawaiian Pizza";
    }

    double price() const override
    {
        return 11.99;
    }
};

class PepperoniPizza : public Pizza
{
public:
    string description() const override
    {
        return "Pepperoni Pizza";
    }

    double price() const override
    {
        return 12.99;
    }
};

class ToppingDecorator : public Pizza
{
    public:
        ToppingDecorator(Pizza &pizza) : m_pizza(&pizza) {};
        string description() const {
            return m_pizza->description();
        }
        double price() const 
        {
            return m_pizza->price();
        }
        virtual ~ToppingDecorator() = default;
    public:
        Pizza* m_pizza;
};

class MushroomDecorator : public ToppingDecorator
{
  public:
    MushroomDecorator(Pizza &pizza) : ToppingDecorator(pizza) {};
    string description() const override{
        return m_pizza->description() += "+ MushroomDecorator";
    }
    double price() const override
    {
        return m_pizza->price() + 5.0;
    }
};

class TomatoDecorator : public ToppingDecorator
{
  public:
    TomatoDecorator(Pizza &pizza) : ToppingDecorator(pizza) {};
    string description() const override{
        return m_pizza->description() += "+ TomatoDecorator";
    }
    double price() const override
    {
        return m_pizza->price() + 6.0;
    }
};


class ExtraCheeseDecorator : public ToppingDecorator
{
  public:
    ExtraCheeseDecorator(Pizza &pizza) : ToppingDecorator(pizza) {};
    string description() const override{
        return m_pizza->description() + "+ ExtraCheeseDecorator";
    }
    double price() const override
    {
        return m_pizza->price() + 7.0;
    }
};


int main()
{
    const std::unique_ptr<Pizza> pizzas[]{
        make_unique<MargheritaPizza>(),
        make_unique<PepperoniPizza>(),
        make_unique<HawaiianPizza>()};
    
    // Pizza* pizaa = pizzas[0].get();
    // pizaa = new MushroomDecorator(*pizaa);
    // pizaa = new TomatoDecorator(*pizaa);
    // pizaa = new ExtraCheeseDecorator(*pizaa);
    // pizaa = new ExtraCheeseDecorator(*pizaa);
//     // top1->description();
//     // top1->price();
    ToppingDecorator * top1 = new MushroomDecorator(*pizzas[0]);
ToppingDecorator * top2 = new TomatoDecorator(*pizzas[0]);
// ToppingDecorator * top3 = new ExtraCheeseDecorator(*pizzas[0]);

// cout << pizzas[0]->description() << " costs $" << pizzas[0]->price() << endl;
    cout << top2->m_pizza->description() << " costs $" << top2->m_pizza->price() << endl;
 
    return 0;
}
