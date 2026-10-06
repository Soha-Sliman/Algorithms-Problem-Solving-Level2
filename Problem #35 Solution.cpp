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
	cout << "\nplease enter a number to search for?\n";
	cin >> Num;
	return Num;
}


bool CheckNumberInArray(int Num, int Arr[100], int Length)
{
	return FindNumberPositionInArray(Num, Arr, Length) != -1;
}


int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], Length;

	FillArray(Arr, Length);

	cout << "\nArray elements:\n";
	PrintArray(Arr, Length);

	int Num = ReadNumber();
	cout << "\nNumber you are looking for is: " << Num << endl;


	if (CheckNumberInArray(Num, Arr, Length))

		cout << "\nYes, The number is found :)\n";

	else
	{
		cout << "\nNo, The number is not found :(\n";
	}

	return 0;
}
