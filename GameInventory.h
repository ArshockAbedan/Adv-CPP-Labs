#pragma once
#include <iostream>
#include <vector>

class GameInventory
{
private:
	std::string name;
	std::string brand;
	int year;
	double price;
public:
	GameInventory();
	GameInventory(std::string name, std::string brand, int year, double price);
	bool isSimilar(const GameInventory& game);
	std::string getName();
	std::string getBrand();
	int getYear();
	double getPrice();
	void displayGame();

};

bool searchInventory(std::vector<GameInventory>& v, GameInventory& game);
void displayInventory(std::vector<GameInventory>& v);
bool addNewGame(std::vector<GameInventory>& v, GameInventory& game);
