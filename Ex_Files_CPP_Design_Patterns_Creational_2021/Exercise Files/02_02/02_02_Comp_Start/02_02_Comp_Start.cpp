// 02_02_Comp_Start.cpp 
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

// Base Entree class
class Entree
{
protected:
	char _entree[10];
public:
	const char *getEntree()
	{
		return _entree;
	}
};


// Base Side class
class Side
{
protected:
	char _side[10];
public:
	char *getSide()
	{
		return _side;
	}
};

class Drink
{
protected:
	char _drink[10];
public:
	Drink()
	{
		cout << "\n Fill cup with soda" << endl;
		strcpy_s(_drink, "soda");
	}
	char *getDrink()
	{
		return _drink;
	}
};

// Complex MealCombo object that contains an Entree, a Side and a Drink object
class MealCombo
{
	private:
		Entree * entree;
		Side * side;
		Drink * drink;
		string _bag;
	public:
		MealCombo(string type)
		{
			type = "meal combo: " + type;
			_bag = type;
		}
		void setEntree(Entree * e)
		{	
			entree = e;
		}
		void setSide(Side * s)
		{
			side = s;
		}
		void setDrink(Drink * d)
		{
			drink = d;
		}
		string openMealBag()
		{
			_bag = _bag + entree->getEntree() + ", " + side->getSide() + ", " + drink->getDrink()
			return _bag;
		}
};