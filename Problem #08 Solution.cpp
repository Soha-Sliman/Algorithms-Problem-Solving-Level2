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

int CountDigitFrequency (int DigitToCheck, int Number)
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

int main()
{
	int Number = ReadPositiveNumber("Please enter a positive number ?");
	int DigitToCheck = ReadPositiveNumber("please enter one digit to check?");

	cout << " Frequency is :" << CountDigitFrequency(DigitToCheck, Number) << endl;

	return 0;
}

