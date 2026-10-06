// Instructor's Reference Solution - C++ Course 5

#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

enum enQuestionsLevel{ EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4 };

enum enOperationType{ Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5 };

string GetQuestionsLevelText(enQuestionsLevel QuestionLevel)
{
	string ArrQuLevel[4] = { "Easy", "Med", "Hard", "Mix" };
	return ArrQuLevel[QuestionLevel - 1];

}

string GetOpTypeSymbol(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return "+";
	case enOperationType::Sub:
		return "-";
	case enOperationType::Mult:
		return "*";
	case enOperationType::Div:
		return "/";
	default:
		return "Mix";
	}
}

short ReadHowManyQuestion()
{
	short NumberOfQuestion;
	do
	{
		cout << "How many questions do you want to answer? ";
		cin >> NumberOfQuestion;
	} while (NumberOfQuestion < 1 || NumberOfQuestion > 10);

	return NumberOfQuestion;
}

enQuestionsLevel ReadQuestionsLevel()
{
	short QuestionLevel = 0;
	do
	{
		cout << "Enter Questions Level: [1]:Easy, [2]:Med, [3]:Hard, [4]:Mix? ";
		cin >> QuestionLevel;
	} while (QuestionLevel < 1 || QuestionLevel > 4);

	return (enQuestionsLevel)QuestionLevel;
}

enOperationType ReadOperationType()
{
	short OperationType;
	do
	{
		cout << "Enter Operation Type: [1]:Add, [2]:Sub, [3]:Mul, [4]:Div, [5]:Mix? ";
		cin >> OperationType;
	} while (OperationType < 1 || OperationType > 5);

	return (enOperationType)OperationType;
}

struct stQuestion {
	int Number1 = 0;
	int Number2 = 0;
	enOperationType OperationType;
	enQuestionsLevel QuestionsLevel;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;
};

struct stQuizz
{
	stQuestion QuestionList[100];
	short NumberOfQuestions;
	enQuestionsLevel QuestionsLevel;
	enOperationType OpType;
	short NumberOfRightAnswers = 0;
	short NumberOfWrongAnswers = 0;
	bool IsPass = false;

};

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

void SetScreenColor(bool Right)
{
	if (Right)
	{
		system("color 2F");
	}
	else
	{
		system("color 4F");
		cout << "\a";
	}
}

int SimpleCalculator(int Num1, int Num2, enOperationType OpType)
{

	switch (OpType)
	{
	case enOperationType::Add:
		return Num1 + Num2;
	case enOperationType::Sub:
		return Num1 - Num2;
	case enOperationType::Mult:
		return Num1 * Num2;
	case enOperationType::Div:
		return Num1 / Num2;
	default:
		return Num1 + Num2;
	}
}

enOperationType GetRandomOperationType()
{
	int Op = RandomNumber(1, 4);
	return (enOperationType)Op;
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionsLevel, enOperationType OpType)
{
	stQuestion Question;
	
	if (QuestionsLevel == enQuestionsLevel::Mix)
	{
		QuestionsLevel = (enQuestionsLevel)RandomNumber(1, 3);
	}

	if (OpType == enOperationType::MixOp)
	{
		OpType = GetRandomOperationType();
	}

	Question.OperationType = OpType;

	switch (QuestionsLevel)
	{
	case enQuestionsLevel::EasyLevel:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionsLevel = QuestionsLevel;
		return Question;

	case enQuestionsLevel::MedLevel:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionsLevel = QuestionsLevel;
		return Question;

	case enQuestionsLevel::HardLevel:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionsLevel = QuestionsLevel;
		return Question;
	}

	return Question;
}

void GenerateQuizzQuestions(stQuizz& Quizz)
{
	for (short i = 0; i < Quizz.NumberOfQuestions; i++)
	{
		Quizz.QuestionList[i] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OpType);

	}
}

int ReadQuestionAnswer()
{
	int Answer = 0;
	cin >> Answer;
	return Answer;
}

void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber)
{
	cout << "\n";
	cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n\n";
	cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
	cout << Quizz.QuestionList[QuestionNumber].Number2 ;
	cout << "\t" << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OperationType);
	cout << "\n__________" << endl;
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber)
{
	if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer)
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = false;
		Quizz.NumberOfWrongAnswers++;

		cout << "Wrong Answer:-( \n";
		cout << "The Right Answer is: ";
		cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer;
		cout << "\n";
	}
	else
	{
		Quizz.QuestionList[QuestionNumber].AnswerResult = true;
		Quizz.NumberOfRightAnswers++;

		cout << "Right Answer:-) \n";
	}
	cout << endl;

	SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
	
}
void AskAndCorrectQuestionListAnswers(stQuizz& Quizz)
{
	for (short i = 0; i < Quizz.NumberOfQuestions; i++)
	{
		PrintTheQuestion(Quizz, i);

		Quizz.QuestionList[i].PlayerAnswer = ReadQuestionAnswer();

		CorrectTheQuestionAnswer(Quizz, i);
	}
	Quizz.IsPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);

}

string GetFinalResultsText(bool Pass)
{
	if (Pass)
		return "Pass :) ";
	else
		return "Fail :( ";
}

void PrintQuizzResults(stQuizz Quizz)
{
	cout << "\n";
	cout << "_______________________________\n\n";
	cout << "Final Results is " << GetFinalResultsText(Quizz.IsPass);
	cout << "\n_____________________________\n\n";

	cout << "Number Of Questions: " << Quizz.NumberOfQuestions << endl;
	cout << "Questions Level    : " << GetQuestionsLevelText(Quizz.QuestionsLevel) << endl;
	cout << "Operation Type     : " << GetOpTypeSymbol(Quizz.OpType) << endl;
	cout << "Number Of Right Answers: " << Quizz.NumberOfRightAnswers << endl;
	cout << "Number Of Wrong Answers: " << Quizz.NumberOfWrongAnswers << endl;
	cout << "_____________________________\n";
}

void PlayMathGame()
{
	stQuizz Quizz;
	Quizz.NumberOfQuestions = ReadHowManyQuestion();
	Quizz.QuestionsLevel = ReadQuestionsLevel();
	Quizz.OpType = ReadOperationType();

	GenerateQuizzQuestions(Quizz);
	AskAndCorrectQuestionListAnswers(Quizz);
	PrintQuizzResults(Quizz);

}

void ResetScreen()
{
	system("cls");
	system("color 0F");

}

void StartGame()
{
	char PlayAgain = 'Y';
	do
	{
		ResetScreen();
		PlayMathGame();

		cout << endl << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}