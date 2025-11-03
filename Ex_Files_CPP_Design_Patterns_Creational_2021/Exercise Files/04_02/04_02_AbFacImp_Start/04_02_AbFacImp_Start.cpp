/// 04_02_AbFacImp_Start.cpp
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//Door Objects
class Door
{
public:
	Door()
	{
	}
	virtual void Open() = 0;
};

class GasCarDoor : public Door
{
public:
	GasCarDoor()
	{
		cout << "Making a door for a gas car." << endl;
	}
	void Open()
	{
		cout << "click" << endl;
	}
};

class ElectricCarDoor : public Door
{
public:
	ElectricCarDoor()
	{
		cout << "Making a door for an electric car" << endl;
	}
	void Open()
	{
		cout << "shhhhh" << endl;
	}
};

//Engine objects
class Engine
{
protected:
	char _sound[15];
public:
	Engine()
	{
		strcpy(_sound, "");
	}
	virtual void Run() = 0;
};

class GasEngine : public Engine
{
public:
	GasEngine()
	{
		strcpy(_sound, "vroom");
		cout << "Making a gas engine." << endl;
	}
	void Run()
	{
		cout << _sound << endl;
	}
};

class ElectricEngine : public Engine
{
public:
	ElectricEngine()
	{
		strcpy(_sound, "SHHHH");
		cout << "Making an electric engine." << endl;
	}
	void Run()
	{
		cout << _sound << endl;
	}
};

//Factories
class CarFactory
{
	public:
		virtual Door* buildDoor() = 0;
		virtual Engine* buildEngine() = 0;
};

class GasCarFactory : public CarFactory
{
	public:
		Door * buildDoor()
		{
			return new GasCarDoor();
		}
		Engine* buildEngine()
		{
			return new GasEngine();
		}
};

class ElectricCarFactory: public CarFactory
{
	public:
		Door * buildDoor()
		{
			return new ElectricCarDoor();
		}
		Engine* buildEngine()
		{
			return new ElectricEngine();
		}
};

int main()
{
	CarFactory* CarPlant;
	int choice;
	cout << "Select a car type: " << endl;
	cout << "1: Gasoline" << endl;
	cout << "2: Electric" << endl;
	cout << "Selection: ";
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
		CarPlant = new GasCarFactory();
		break;
	case 2:
		CarPlant = new ElectricCarFactory();
		break;
	default:
		CarPlant = nullptr;
	}
	Door* door = CarPlant->buildDoor();
	door->Open();

	Engine* engine = CarPlant->buildEngine();
	engine->Run();
}

