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

int main()
{
	cout <<"Reverse number is : " << 
		ReverseNumber(ReadPositiveNumber("please enter a positive number ?")) << "\n";

	return 0;
}