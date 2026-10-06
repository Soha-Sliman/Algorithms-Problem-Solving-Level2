#include<iostream>
#include<string>
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

float SumOfArrayRandom(int Arr[100], int Length)
{
	int Sum = 0;
	for (int i = 0; i < Length; i++)
	{
		Sum += Arr[i];
	}
	return Sum;
}

float AverageArray(int Arr[100], int Length)
{
	return (float)SumOfArrayRandom(Arr, Length) / Length;
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], Length;

	FillArray(Arr, Length);


	cout << "Array elements: \n";
	PrintArray(Arr, Length);

	cout << "Average of numbers = \n";
	cout << AverageArray(Arr, Length) << endl;

	return 0;
}