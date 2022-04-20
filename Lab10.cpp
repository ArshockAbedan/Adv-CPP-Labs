//============================================================================
// Name        : Lab10.cpp
// Author      : Aref Abedjooy
// Version     : 1.0
// Copyright   : Copyright (c) 2022, Aref Abedjooy. No Rights Reserved.
// Description : This is a sample code for Lab-10
//               in the "CSCI 1061U – Programming Workshop II" course
//               which was taught at Ontario tech University during Winter 2022 term.
//============================================================================
#include "GameInventory.h"
#include "GameInventory.cpp"
int main()
{
    // Set of existing games
    std::vector<GameInventory> games = {
        {"Need for Speed", "XBox", 2018, 45.0},
        {"Hitman 2", "Playstation", 2020, 75.5},
        {"Mario Brothers", "Nintendo", 2010, 30.0},
        {"Assassin's Creed", "Playstation", 2021, 70.5},
        {"Uncharted 4: A Thief's End", "Playstation", 2020, 85.0},
        {"Spiderman Miles Morales", "XBox", 2021, 65.5},
        {"Resident Evil", "XBox", 2018, 45.0},
    };

    // Displaying current Games in the Inventory
    std::cout << "Current Games in the Inventory" << std::endl;
    std::cout << "**********************************" << std::endl;
    displayInventory(games);

    // Adding a new game
    GameInventory game = GameInventory("Hitman 3", "Playstation", 2022, 95);
    std::cout << "\nAdding another game in the Inventory..." << std::endl;

    // Checks to see if this game already exists in the collection
    if (searchInventory(games, game))
    {
        std::cout << "\nFollowing Game already exists in the Inventory..." << std::endl;
        game.displayGame();
    }
    else
    {
        if (addNewGame(games, game))
        {
            std::cout << "\nFollowing Game added to the inventory successfully..." << std::endl;
            game.displayGame();
            std::cout << std::endl;
        }
    }

    // Displaying current Games in the Inventory
    std::cout << "Current Games in the Inventory" << std::endl;
    std::cout << "**********************************" << std::endl;
    displayInventory(games);

    // Adding another new game which already exists in the inventory
    game = GameInventory("Need for Speed", "XBox", 2018, 45.0);
    std::cout << "\nAdding another game in the Inventory..." << std::endl;

    // Checks to see if this game already exists in the collection
    if (searchInventory(games, game))
    {
        std::cout << "\nFollowing Game already exists in the Inventory..." << std::endl;
        game.displayGame();
        std::cout << std::endl;
    }
    else
    {
        if (addNewGame(games, game))
        {
            std::cout << "\nFollowing Game added to the inventory successfully..." << std::endl;
            game.displayGame();
            std::cout << std::endl;
        }
    }

    // Displaying current Games in the Inventory
    std::cout << "Current Games in the Inventory" << std::endl;
    std::cout << "**********************************" << std::endl;
    displayInventory(games);

    return 0;
}
