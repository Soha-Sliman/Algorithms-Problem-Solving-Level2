#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

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

void FillArray(int Arr[100], int& Length)
{

	for (int i = 0; i < Length; i++)
		Arr[i] = RandomNumber(1, 100);
}

void SumOf2Arrays(int Arr[100], int Arr2[100], int ArrSum[100], int Length)
{
	for (int i = 0; i < Length; i++)
	{
		ArrSum[i] = Arr[i] + Arr2[i];
	}
}

void PrintArray(int Arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
		cout << Arr[i] << " ";

	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], Arr2[100], ArrSum[100];
	int Length = ReadPositiveNumber("please enter number of elements: \n");

	FillArray(Arr, Length);
	FillArray(Arr2, Length);

	SumOf2Arrays(Arr, Arr2, ArrSum, Length);

	cout << "Array elements: \n";
	PrintArray(Arr, Length);

	cout << "Array2 elements: \n";
	PrintArray(Arr2, Length);

	cout << "Sum of array and array2 elements : \n";
	PrintArray(ArrSum, Length);

	return 0;
}