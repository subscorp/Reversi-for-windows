/******************************************
*Ori Hirshfeld
*201085776
*Amichai Wollin
*300582392
******************************************/

#include <iostream>
#include "Board.h"
#include "LocalPlayer.h"
#include "AIPlayer.h"
#include "GameManager.h"

using namespace std;

int main()
{
	int choice;
	GameManager *manager;
	Logic *gameLogic;
	Player *playerO;
	Player *playerX;

	//presenting choices to the user and getting input
	cout <<"Welcome to Reversi!" << endl;
	cout << "enter 1 to play against AI player" << endl;
	cout << "enter 2 to play against Human player" <<endl;
	cin >> choice;
	cin.ignore();
	switch(choice)
	{

	//using standard logic and playing against AI player
	case 1:
	{
		gameLogic = new StandardLogic();
		playerX = new LocalPlayer('X', gameLogic);
		playerO = new AIPlayer('O', gameLogic);
		cout << "starting a game against AI player" <<endl << endl;
		manager = new GameManager(gameLogic, playerX, playerO);
		break;
	}

	//using standard logic and playing against another human player
	case 2:
	{
		cout << "starting game against Human player" <<endl << endl;
		manager = new GameManager();
		break;
	}

	//defualt case is the same as case 2
	default:
	{
		cout << "starting game against Human player" << endl << endl;
		manager = new GameManager();
		break;
	}

	}
	manager->runGame();
	delete manager;

	return 0;
}