#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;


enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };


int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}


char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::SmallLetter:
	{
		return char(RandomNumber(97, 122));
		break;
	}
	case enCharType::CapitalLetter:
	{
		return char(RandomNumber(65, 90));
		break;
	}
	case enCharType::SpecialCharacter:
	{
		return char(RandomNumber(33, 47));
		break;
	}
	case enCharType::Digit:
	{
		return char(RandomNumber(48, 57));
		break;
	}
	default:
		return '\0';
	}
}


void PrintArray(string Arr[100], int Length)
{
	cout << "\nArray elements:\n\n";
	for (int i = 0; i < Length; i++)
	{
		cout << "Array[" << i << "] : ";
		cout << Arr[i] << "\n";
	}

	cout << "\n";
}


int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}


string GenerateWord(enCharType CharType, short Length)
{
	string Word;
	for (int i = 1; i <= Length; i++)
	{
		Word = Word + GetRandomCharacter(CharType);
	}
	return Word;
}


string GenerateKey()
{
	string Key = "";
	Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
	return Key;
}


void FillArray(string Arr[100], int Length)
{

	for (int i = 0; i < Length; i++)
		Arr[i] = GenerateKey();
}


int main()
{

	srand((unsigned)time(NULL));

	string Arr[100];
	int Length = 0;

	Length = ReadPositiveNumber("How many keys do you want to generate?\n");

	FillArray(Arr, Length);

	PrintArray(Arr, Length);

	return 0;

}

