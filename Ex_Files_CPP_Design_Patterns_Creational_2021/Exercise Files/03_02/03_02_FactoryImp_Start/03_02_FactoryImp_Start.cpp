// 03_02_FactoryImp_Start.cpp 
//

// #include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// Product from which the concrete products will inherit from 
class Coffee
{
protected:
	char _type[15];
public:
	Coffee()
	{
	}
	char *getType()
	{
		return _type;
	}
	virtual ~Coffee() = default;
};

// One concrete class
class Espresso : public Coffee
{
public:
	Espresso() : Coffee()
	{
		strcpy(_type, "Espresso");
		cout << endl << "Making a cup of espresso" << endl;
		cout << "Grind and brew one scoop of espresso beans." << endl;
	}
};

// Another concrete class
class Cappuccino : public Coffee
{
public:
	Cappuccino() : Coffee()
	{
		strcpy(_type, "Cappuccino");
		cout << endl << "Making a cup of cappuccino" << endl;
		cout << "Grind and brew one scoop of espresso beans." << endl;
		cout << "Heat and foam milk." << endl;
	}
};

class CoffeeFacory{
	private:
		Coffee * _coffee;
	
	public:
		Coffee * getCoffee(){
			int choice;
			cin >> choice;
			switch(choice){
				case 1:
					return new Espresso();
				case 2:
					return new Cappuccino();
				default:
					return nullptr;
			}
		}
		virtual ~CoffeeFacory() = default;  
};



int main()
{
	CoffeeFacory coffeeFacory;
	Coffee * cup;
	cup = coffeeFacory.getCoffee();
	std::cout << cup->getType() << std::endl;
}