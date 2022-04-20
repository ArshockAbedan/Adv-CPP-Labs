#include "GameInventory.h"

GameInventory::GameInventory()
{
	name = "";
	brand = "";
	year = 0;
	price = 0.0;
}

GameInventory::GameInventory(std::string name, std::string brand, int year, double price)
{
	this->name = name;
	this->brand = brand;
	this->year = year;
	this->price = price;
}
bool GameInventory::isSimilar(const GameInventory& game)
{
	if ((this->name == game.name) && (this->brand == game.brand) && (this->year = game.year) && (this->price == game.price))
	{
		return true;
	}
	else
	{
		return false;
	}
}
std::string GameInventory::getName()
{
	return this->name;
}
std::string GameInventory::getBrand()
{
	return this->brand;
}
int GameInventory::getYear()
{
	return this->year;
}
double GameInventory::getPrice()
{
	return this->price;
}

void GameInventory::displayGame()
{
	std::cout << "Name: " << this->name
		<< ", Brand: " << this->brand
		<< ", Year: " << this->year
		<< ", Price: " << this->price << std::endl;
}

bool searchInventory(std::vector<GameInventory>& v, GameInventory& game)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i).isSimilar(game))
		{
			return true;
		}
	}
	return false;
}
void displayInventory(std::vector<GameInventory>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << "Name: " << v.at(i).getName()
			<< ", Brand: " << v.at(i).getBrand()
			<< ", Year: " << v.at(i).getYear()
			<< ", Price: " << v.at(i).getPrice() << std::endl;
	}
}

bool addNewGame(std::vector<GameInventory>& v, GameInventory& game)
{
	try
	{
		v.push_back(game);
		return true;
	}
	catch (...)
	{
		return false;
	}

}
