#include<iostream>
#include<string>

using namespace std;

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

void ReadArray(int arr[100], int& Length)
{
	cout << "please enter number of elements: \n";
	cin >> Length;

	cout << " enter array elements: \n";

	for (int i = 0; i < Length; i++)
	{
		cout << "Element [" << i + 1 << "] : ";
		cin >> arr[i];
	}
	cout << endl;
}

void PrintArray(int arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
		cout << arr[i] << " ";
	
	cout << "\n";
}

int TimesRepeated(int Number, int arr[100], int Length)
{
	int count = 0;
	for (int i = 0; i < Length; i++)
	{
		if (Number == arr[i])
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int arr[100], Length, Number;

	ReadArray(arr, Length);

	Number = ReadPositiveNumber("please enter the number you want to check: ");

	cout << "\nOriginal Array: ";
	PrintArray(arr, Length);

	cout << "\nNumber " << Number;
	cout << " is repeated ";
	cout << TimesRepeated(Number, arr, Length) << " Times(s)\n";

	return 0;
}