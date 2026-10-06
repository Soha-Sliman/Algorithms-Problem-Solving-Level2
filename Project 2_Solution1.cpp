#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

enum enQuestionsLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };

enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, mix = 5 };

struct stQuestionsResults
{
	int NumberOfQuestions = 0;
	enQuestionsLevel QuestionsLevel = {};
	enOperationType OperationType = {};
	int NumberOfRightAnswers = 0;
	int NumberOfWrongAnswers = 0;
	bool IsPass;
};

struct stQuestion {
	int Number1 = 0;
	int Number2 = 0;
	enOperationType OperationType = enOperationType::Add;
	enQuestionsLevel QuestionsLevel = enQuestionsLevel::Easy;
	int RightAnswer = 0;
	int PlayerAnswer = 0;
};

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

int ReadHowManyQuestions()
{
	int Questions;

	cout << "How many questions do you want to answer?";
	cin >> Questions;
	return Questions;
}

enQuestionsLevel ReadQuestionsLevel()
{
	int Level;
	cout << "\nEnter Questions Level: [1]:Easy, [2]:Med, [3]:Hard, [4]:Mix?";
	cin >> Level;
	return (enQuestionsLevel)Level;
}

enOperationType ReadOperationType()
{
	int Operation;
	cout << "\nEnter Operation Type: [1]:Add, [2]:Sub, [3]:Mul, [4]:Div, [5]:mix?";
	cin >> Operation;
	return (enOperationType)Operation;
}

void SetScreenColor(bool AnswerResults)
{
	switch (AnswerResults)
	{
	case true:
		system("color 2F"); //turn screen to green 
		break;

	case false:
		system("color 4F"); //turn screen to red
		cout << "\a"; //beep sound
		break;

	default:
		system("color 6F"); //turn screen to yellow
		break;


	}
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionsLevel, enOperationType OperationType)
{
	stQuestion Question;

	Question.QuestionsLevel = QuestionsLevel;
	enQuestionsLevel TempLevel = QuestionsLevel;

	if (TempLevel == enQuestionsLevel::Mix)
	{
		TempLevel = (enQuestionsLevel)RandomNumber(1, 3);
	}
	switch (TempLevel)
	{
	case enQuestionsLevel::Easy:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);
		break;
	case enQuestionsLevel::Med:
		Question.Number1 = RandomNumber(10, 100);
		Question.Number2 = RandomNumber(10, 100);
		break;
	case enQuestionsLevel::Hard:
		Question.Number1 = RandomNumber(100, 1000);
		Question.Number2 = RandomNumber(100, 1000);
		break;
	}
	Question.OperationType = OperationType;
	enOperationType TempOpType = OperationType;

	if (TempOpType == enOperationType::mix)
	{
		TempOpType = (enOperationType)RandomNumber(1, 4);
	}
	switch (TempOpType)
	{
	case enOperationType::Add:
		Question.OperationType = enOperationType::Add;
		Question.RightAnswer = Question.Number1 + Question.Number2;
		break;
	case enOperationType::Sub:
		Question.OperationType = enOperationType::Sub;
		Question.RightAnswer = Question.Number1 - Question.Number2;
		break;
	case enOperationType::Mul:
		Question.OperationType = enOperationType::Mul;
		Question.RightAnswer = Question.Number1 * Question.Number2;
		break;
	case enOperationType::Div:
		Question.OperationType = enOperationType::Div;
		Question.RightAnswer = Question.Number1 / Question.Number2;
		break;
	
	}
	return Question;
}

int ReadPlayerAnswer()
{
	int Answer;
	cin >> Answer;
	return Answer;
}

string GetOpType(enOperationType OpType)
{
	string ArrOpType[5] = {"+", "-", "*", "/", "mix"};
	
	return ArrOpType[OpType - 1];
}

bool CheckAnswer(stQuestion &Question)
{
	if (Question.PlayerAnswer == Question.RightAnswer)
	{
		cout << "Right Answer:-) \n";
		SetScreenColor(true);
		return true;
	}
	else
	{
		cout << "Wrong Answer:-( \n";
		cout << "The Right Answer is: " << Question.RightAnswer << endl;
		SetScreenColor(false);
		return false;
	}
}

void PrintQuestion(stQuestion Que)
{
	
	cout << Que.Number1 << endl;
	cout << "\t" << GetOpType(Que.OperationType) << endl;
	cout <<Que.Number2 << endl;
	cout << "_________" << endl;

	
}

stQuestionsResults PlayGame()
{
	stQuestionsResults QueResult;

	 QueResult.NumberOfQuestions = ReadHowManyQuestions();
	QueResult.QuestionsLevel= ReadQuestionsLevel();
	QueResult.OperationType = ReadOperationType();

	for (int i = 1; i <= QueResult.NumberOfQuestions; i++)
	{

		cout << "\nQuestion[" << i << "/" << QueResult.NumberOfQuestions << "]" << endl;
	
		stQuestion Que;

		Que = GenerateQuestion(QueResult.QuestionsLevel, QueResult.OperationType);

		PrintQuestion(Que);

		Que.PlayerAnswer = ReadPlayerAnswer();

		if (CheckAnswer(Que))
		{
			QueResult.NumberOfRightAnswers++;
		}
		else
		{
			QueResult.NumberOfWrongAnswers++;
		}
	}
		 QueResult.IsPass = (QueResult.NumberOfRightAnswers >= QueResult.NumberOfWrongAnswers);
		 return QueResult;

}

void ResetScreenColor()
{
	system("cls");
	system("color 0F");

}

string GetFinalResultsText(stQuestionsResults QueResult)
{
	if (QueResult.IsPass)
		return "Pass :) ";
	else
		return "Fail :( ";
}

string GetQuestionsLevelText(enQuestionsLevel QuLevel)
{
	string ArrQuLevel[4] = { "Easy", "Med", "Hard", "Mix" };

	return ArrQuLevel[QuLevel - 1];
}

void StartGame()
{
	char PlayAgain = 'Y';
	do
	{
		ResetScreenColor();

		stQuestionsResults QuResult = PlayGame();
		cout << "_________________________________\n";
		cout << "Final Results is " << GetFinalResultsText(QuResult) << endl;
		cout << "_________________________________\n";
		cout << "Number Of Questions    :" << QuResult.NumberOfQuestions << endl;
		cout << "Questions Level        :" <<  GetQuestionsLevelText(QuResult.QuestionsLevel) << endl;
		cout << "Operation Type         :" <<GetOpType (QuResult.OperationType) << endl;
		cout << "Number Of Right Answer :" << QuResult.NumberOfRightAnswers << endl;
		cout << "Number Of Wrong Answer :" << QuResult.NumberOfWrongAnswers << endl;

		cout << "_________________________________\n";

		cout << "\nDo you want to play again?Y/N? ";
		cin >> PlayAgain;
        
	} while (PlayAgain == 'Y' || PlayAgain =='y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;

}