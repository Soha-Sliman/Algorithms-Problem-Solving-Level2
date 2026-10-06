#include<iostream>

using namespace std;

int ReadNumber()
{
	int Number;
	cout << "\nplease enter a number?";
	cin >> Number;
	return Number;
}

void AddArrayElement(int Num, int Arr[100], int &Length)
{
	Length++;
	Arr[Length - 1] = Num;
}

void InputUserNumbersInArray(int Arr[100], int &Length)
{
	bool AddMore = true;

	do
	{
		AddArrayElement(ReadNumber(), Arr, Length);
		cout << "\nDo you want to add more numbers? [0]:No,[1]:Yes? ";
		cin >> AddMore;

	} while (AddMore);

}


void PrintArray(int Arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
		cout << Arr[i] << " ";

	cout << "\n";
}

int main()
{
	int Arr[100], Length = 0;

	InputUserNumbersInArray(Arr, Length);


	cout << "\nArray length: " << Length << endl;

	cout << "\nArray elements:";
	PrintArray(Arr, Length);

	return 0;
}