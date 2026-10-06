#include<iostream>

using namespace std;

void FillArray(int Arr[100], int& Length)
{
	Length = 10;

	Arr[0] = 10;
	Arr[1] = 10;
	Arr[2] = 10;
	Arr[3] = 50;
	Arr[4] = 50;
	Arr[5] = 70;
	Arr[6] = 70;
	Arr[7] = 70;
	Arr[8] = 70;
	Arr[9] = 90;
}


void PrintArray(int Arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
		cout << Arr[i] << " ";

	cout << "\n";
}


int FindNumberPositionInArray(int Num, int Arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
	{
		if (Arr[i] == Num)
			return i;
	}
	return -1;
}

bool CheckNumberInArray(int Num, int Arr[100], int Length)
{
	return FindNumberPositionInArray(Num, Arr, Length) != -1;
}


void AddArrayElement(int Num, int Arr[100], int& Length)
{
	Length++;
	Arr[Length - 1] = Num;
}


void CopyDistinctNumbersToArray(int Arr[100], int Arr2[100], int Length, int& Length2)
{
	for (int i = 0; i < Length; i++)
	{
		if (!CheckNumberInArray(Arr[i], Arr2, Length2))
		{
			AddArrayElement(Arr[i], Arr2, Length2);
		}
	}
}

int main()
{
	int Arr[100], Arr2[100], Length = 0, Length2 = 0;

	FillArray(Arr, Length);

	cout << "Array elements:\n";
	PrintArray(Arr, Length);

	CopyDistinctNumbersToArray(Arr, Arr2, Length, Length2);

	cout << "Distinct numbers in array2:\n";
	PrintArray(Arr2, Length2);

	return 0;
}