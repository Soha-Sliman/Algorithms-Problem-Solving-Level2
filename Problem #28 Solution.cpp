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

void CopyArray(int Arr[100], int Arr2[100], int Length)
{
	for (int i = 0; i < Length; i++)
		Arr2[i] = Arr[i];
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], Length, Arr2[100];

	FillArray(Arr, Length);


	cout << "Array elements: \n";
	PrintArray(Arr, Length);

	CopyArray(Arr, Arr2, Length);

	cout << "Array elements before copy: \n";
    PrintArray(Arr, Length);

	cout << "Array elements after copy: \n";
	PrintArray(Arr2, Length);

	return 0;
}