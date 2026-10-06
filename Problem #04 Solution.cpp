#include<iostream>
#include<string>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number < 0);
	return Number;
}

bool CheckPerfectNumber(int Number)
{
	int Sum = 0;
	for (int i = 1; i < Number; i++)
	{
		if (Number % i == 0)
		{
			Sum += i;
		}
	}
	return Sum == Number;
}

void PrintPerfectNumberFrom1ToN(int Number)
{
	for (int i = 1; i <= Number; i++)
	{
		if (CheckPerfectNumber(i))
		{
			cout << i << " is perfect number1" << endl;
		}
	}
}

int main()
{
	int Number = ReadPositiveNumber("Please enter a positive number: ");
	PrintPerfectNumberFrom1ToN(Number);
	return 0;
}