#include<iostream>;
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
		Arr[i] = RandomNumber(-100, 100);
}


void PrintArray(int Arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
		cout << Arr[i] << " ";

	cout << "\n";
}


int CountNegativeNumbersInArray(int Arr[100], int Length)
{
	int Count = 0;
	for (int i = 0; i < Length; i++)
	{
		if (Arr[i] < 0)
		{
			Count++;
		}
	}
	return Count;
}


int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], Length;
	FillArray(Arr, Length);

	cout << "\nArray elements: \n";
	PrintArray(Arr, Length);

	cout << "\nNegative numbers count is: " << CountNegativeNumbersInArray(Arr, Length) << endl;

	return 0;
}