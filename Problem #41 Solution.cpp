#include<iostream>

using namespace std;

//void FillArray(int Arr[100], int& Length)
//{
	//Length = 6;

	//Arr[0] = 10;
	//Arr[1] = 20;
	//Arr[2] = 30;
	//Arr[3] = 30;
	//Arr[4] = 20;
	//Arr[5] = 10;
//}
void FillArray(int Arr[100], int& Length)
{
	cout << "\nplease enter number of elements?";
	cin >> Length;

	for (int i = 0; i < Length; i++)
	{
		cout << "Element [" << i + 1 << "]: ";
		cin >> Arr[i];
	}
}


void PrintArray(int Arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
		cout << Arr[i] << " ";
	cout << "\n";
}


bool IsPalindromeArray(int Arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
	{
		if (Arr[i] != Arr[Length - i - 1])
		{
			return false;
		}
	}
	return true;
}


int main()
{
	int Arr[100], Length;

	FillArray(Arr, Length);

	cout << "\nArray elements:\n";
	PrintArray(Arr, Length);

	if (IsPalindromeArray(Arr, Length))
		cout << "\nYes,Array is palindrome\n";
	else
		cout << "\nNo,Array is not palindrome\n";

	return 0;
}