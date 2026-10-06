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
		Arr[i] = i + 1;
}

void Swap(int& A, int& B)
{
	int Temp = A;
	A = B;
	B = Temp;
}

void ShuffleArray(int Arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
	{
		int index = RandomNumber(0, Length-1);
		int index1 = RandomNumber(0, Length-1) ;

		Swap(Arr[index], Arr[index1]);
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

	int Arr[100];
	int Length = ReadPositiveNumber("please enter number of elements: \n");

	FillArray(Arr, Length);

	cout << "\nArray elements before shuffle: \n";
	PrintArray(Arr, Length);

	ShuffleArray(Arr, Length);

	cout << "\n";
	cout << "Array elements after shuffle: \n";
	PrintArray(Arr, Length);

	return 0;
}

