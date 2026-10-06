#include <iostream>

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

int ReverseNumber(int Number)
{
	int Remainder = 0, Count = 0;

	while (Number > 0)
	{

		Remainder = Number % 10;
		Number /= 10;
		Count = Count * 10 + Remainder;
	}
	return Count;

}

bool CheckPalindromeNumber(int Number)
{
	return (ReverseNumber(Number) == Number);
}

int main()
{
	if (CheckPalindromeNumber(ReadPositiveNumber("please enter a positive number?\n")))
		cout << " Yes, The number is a palindrome\n";
	else
		cout << "No,The number is not a palindrome\n";
	return 0;
}