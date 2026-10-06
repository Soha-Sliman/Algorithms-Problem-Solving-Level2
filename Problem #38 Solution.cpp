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


void AddArrayElement(int Num, int Arr[100], int& Length)
{
	Length++;
	Arr[Length - 1] = Num;
}


void CopyOddNumbers(int Arr[100], int Arr2[100], int Length1, int& Length2)
{
	for (int i = 0; i < Length1; i++)
	{
		if (Arr[i] % 2 != 0)
		{
			AddArrayElement(Arr[i], Arr2, Length2);
		}
	}
}



int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], Arr2[100], Length1 = 0, Length2 = 0;

	FillArray(Arr, Length1);

	CopyOddNumbers(Arr, Arr2, Length1, Length2);

	cout << "\nArray elements: \n";
	PrintArray(Arr, Length1);


	cout << "\nArray2 odd numbers: \n";
	PrintArray(Arr2, Length2);

	return 0;
}