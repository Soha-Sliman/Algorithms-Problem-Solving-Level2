#include<iostream>
#include<string>

using namespace std;

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

int CountDigitFrequency(int DigitToCheck, int Number)
{
	int Remainder = 0;
	int FreqCount = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;

		if (DigitToCheck == Remainder)
		{
			FreqCount++;
		}
	}
	return FreqCount;
}

void PrintAllDigitsFrequency(int Number)
{
	for (int i = 0; i < 10; i++)
	{
		int DigitFreq = 0;
		DigitFreq = CountDigitFrequency(i, Number);

		if (DigitFreq > 0)
		{
			cout << "Digit " << i << "Frequency is :" << DigitFreq << "Times(s).\n";
		}
		
	}
}

int main()
{
	int Number = ReadPositiveNumber("please enter a number?");
	PrintAllDigitsFrequency(Number);
	return 0;
}