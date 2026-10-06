#include<iostream>
#include<string>

using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

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

enPrimeNotPrime CheckPrime(int Number)
{
	if (Number == 1)
	{
		return enPrimeNotPrime::Prime;
	}

	int counter = 0;
	for (int i = 1; i <= Number; i++)
	{

		if (Number % i == 0)
		{
			counter++;
		}
	}
	if (counter == 2)
	{
		return enPrimeNotPrime::Prime;
	}

	return enPrimeNotPrime::NotPrime;

}

void PrintPrimeNumberFrom1ToN(int Number)
{

	cout << "Prime numbers from 1 to " << Number << " are: " << endl;
	for (int i = 1; i <= Number; i++)
	{
		if (CheckPrime(i) == enPrimeNotPrime::Prime)
		{
			cout << i << endl;
		}
	}
}

int main()
{
	PrintPrimeNumberFrom1ToN(ReadPositiveNumber("Enter number?"));

	return 0;
}