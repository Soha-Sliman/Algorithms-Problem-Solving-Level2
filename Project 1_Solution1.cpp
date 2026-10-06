#include<iostream>
#include<cstdlib>
#include<string>


using namespace std;

enum enGameChoices{stone = 0, paper = 1, scissor = 2 };

enum enWinnerChoice {WinningPlayer1 = 0, WinningComputer = 1, Draw = 2};

struct stGameResults
{
	int GameRounds = 0,Player1WonTimes = 0, ComputerWonTimes = 0, DrawTimes = 0;

	enWinnerChoice FinalWinner = enWinnerChoice::Draw;

};


int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}


int ReadHowManyRounds()
{
	int Num;

	cout << "How many rounds 1 to 10 ?\n";

	cin >> Num;
	return Num;
}


enGameChoices ComputerChoice()
{

	return (enGameChoices)RandomNumber(0, 2);
}


enGameChoices Player1Choice()
{
	int Choice;

	do
	{
		cout << "\nYour choice: [0]:stone, [1]:paper, [2]:scissors? ";

		cin >> Choice;

	} while (Choice < 0 || Choice > 2);

	return (enGameChoices)Choice;
}


enWinnerChoice ComparingResults(enGameChoices Player1Choice, enGameChoices ComputerChoice)
{
	if (Player1Choice == ComputerChoice)
	{
		return enWinnerChoice::Draw;
	}
	else if(Player1Choice == enGameChoices::stone && ComputerChoice == enGameChoices::scissor || 
		Player1Choice == enGameChoices::paper && ComputerChoice == enGameChoices::stone ||
		Player1Choice == enGameChoices::scissor && ComputerChoice == enGameChoices::paper)
	{
		return enWinnerChoice::WinningPlayer1;
	}
	else
	{
		return enWinnerChoice::WinningComputer;
	}

}

string GetChoiceName(enGameChoices Choice)
{
	switch (Choice)
	{
	case enGameChoices::stone:
		return "stone";
	case enGameChoices::paper:
		return "paper";
	case enGameChoices::scissor:
		return "scissor";
	default:
		return "stone";

	}
}


string GetWinnerName(enWinnerChoice Winner)
{
	switch (Winner)
	{
	case enWinnerChoice::WinningPlayer1:
		return "Player1";
	case enWinnerChoice::WinningComputer:
		return "Computer";
	case enWinnerChoice::Draw:
		return "Draw";
	default:
		return "Draw";
	}

}


stGameResults PlayGame()
{
	int Rounds = ReadHowManyRounds();

	stGameResults GameResults = {};

	for (int i = 1; i <= Rounds; i++)
	{
		cout << "\nRound[" << i << "]begins:\n";

		enGameChoices Player1 = Player1Choice();

		cout << "\n__________Round[" << i << "]__________\n";

		GameResults.GameRounds++;

		enGameChoices Computer = ComputerChoice();

		enWinnerChoice Winner = ComparingResults(Player1, Computer);


		cout << "\nPlayer choice : " << GetChoiceName(Player1);

		cout << "\nComputer choice : " << GetChoiceName(Computer);

		
		if (Winner == enWinnerChoice::WinningPlayer1)
		{
			system("color 2A");

			cout << "\nRound winner : " << GetWinnerName(Winner) << endl;

			GameResults.Player1WonTimes++;
		}
		else if (Winner == enWinnerChoice::WinningComputer)
		{
			system("color C0");

			cout << "\a\nRound winner : " << GetWinnerName(Winner) << endl;

			GameResults.ComputerWonTimes++;
		}
		else if (Winner == enWinnerChoice::Draw)
		{

			system("color 6E");

			cout << "\nRound winner : " << GetWinnerName(Winner) << endl;

			GameResults.DrawTimes++;
		}

		cout << "\n_________________________________________\n";
	}
	

	return GameResults;
}

enWinnerChoice ComparingWinner(stGameResults GameResults)
{
	
	if (GameResults.Player1WonTimes > GameResults.ComputerWonTimes)
	{
		return enWinnerChoice::WinningPlayer1;
	}
	else if (GameResults.Player1WonTimes < GameResults.ComputerWonTimes)
	{
		return enWinnerChoice::WinningComputer;
	}
	else
	{
		return enWinnerChoice::Draw;
	}
}

void StartGame()
{
	
	char PlayAgain = 'Y';

	do
	{
		system("cls");
		system("color 0F");

		stGameResults GameResults = PlayGame();

		cout << "\n\t\t____________________________________________\n";

		cout << "\n \t\t             +++ Game  Over +++ \t\t \n";

		cout << "\n\t\t____________________________________________\n";

		cout << "\n\t\t_______________[Game Results]_______________\n";

		cout << "\n\t\tGame Rounds        : " << GameResults.GameRounds;

		cout << "\n\t\tPlayer1 won times  : " << GameResults.Player1WonTimes;

		cout << "\n\t\tComputer won times : " << GameResults.ComputerWonTimes;

		cout << "\n\t\tDraw times         : " << GameResults.DrawTimes;

		GameResults.FinalWinner = ComparingWinner(GameResults);

		cout << "\n\t\tFinal winner       : " << GetWinnerName(GameResults.FinalWinner);

		cout << "\n\t\t____________________________________________\n";

		cout << "\n\t\tDo you want to play again?Y/N? ";

		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}


int main()
{

	srand((unsigned)time(NULL));

	StartGame();

	return 0;

}