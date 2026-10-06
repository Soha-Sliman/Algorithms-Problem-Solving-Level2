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

void CopyArrayInReverseOrder(int Arr[100], int Arr2[100], int Length)
{
	int j = 0;

	for (int i = Length - 1; i >= 0; i--)
	{
		Arr2[j] = Arr[i];
		j++;
	}

	//for(int i = 0; i < Length; i++) //طريقة ثانية 
	//  Arr2[i] =  Arr[Length-1-i];
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

	int Arr[100], Arr2[100];
	int Length = ReadPositiveNumber("please enter number of elements: \n");

	FillArray(Arr, Length);

	CopyArrayInReverseOrder(Arr, Arr2, Length);

	cout << "\nArray elements: \n";
	PrintArray(Arr, Length);

	cout << "\nArray 1 elements after copy:\n";
	PrintArray(Arr2, Length);

	return 0;
}

