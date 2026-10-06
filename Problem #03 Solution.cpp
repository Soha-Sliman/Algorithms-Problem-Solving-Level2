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

void PrintResult(int Number)
{
	if (CheckPerfectNumber(Number))
	{
		cout << Number << " is perfect number." << endl;
	}
	else
	{
		cout << Number << " is not perfect number." << endl;
	}
}

int main()
{
	int Number = ReadPositiveNumber("Please enter a positive number: ");
	PrintResult(Number);
	return 0;
}