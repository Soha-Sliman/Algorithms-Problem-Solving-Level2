#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}


void FillArray(int Arr[100], int& Length)
{
	cout << "please enter number of elements: \n";
	cin >> Length;

	for (int i = 0; i < Length; i++)
		Arr[i] = RandomNumber(1, 100);
}


void PrintArray(int Arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
		cout << Arr[i] << " ";

	cout << "\n";
}


int FindNumberPositionInArray(int Number, int Arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
	{
		if (Arr[i] == Number)
			return i;
	}
	return -1;
}

int ReadNumber()
{
	int Num;
	cout << "please enter a number to search for?\n";
	cin >> Num;
	return Num;
}


int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], Length;
	FillArray(Arr, Length);

	cout << "Array elements:\n";
	PrintArray(Arr, Length);

	int Num = ReadNumber();
	cout << "Number you are looking for is: " << Num << endl;

	int NumPosition = FindNumberPositionInArray(Num, Arr, Length);

	if (NumPosition == -1)
		cout << "The number is not found.\n";

	else
	{
		cout << "The number found at position: " << NumPosition << endl;
		cout << "The number found its order : " << NumPosition + 1<< endl;

	}

	return 0;
}
