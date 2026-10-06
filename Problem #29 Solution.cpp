#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

enum  enPrimeNotPrime { Prime = 1, NotPrime = 2 };

enPrimeNotPrime CheckPrime(int Number)
{
	int P = round(Number / 2);

	for (int i = 2; i <= P ; i++)
	{
		if (Number % i == 0)
			return enPrimeNotPrime::NotPrime;
	}
	return enPrimeNotPrime::Prime;
}


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

void CopyOnlyPrimeNumbers(int Arr[100], int Arr2[100], int Length, int& Length2)
{
	int count = 0;
	for (int i = 0; i < Length; i++)
	{
		if (CheckPrime(Arr[i]) == enPrimeNotPrime::Prime)
		{
			Arr2[count] = Arr[i];
			count++;
		}
	}
	
	Length2 = count;

}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], Length, Arr2[100], Length2 = 0;

	FillArray(Arr, Length);

	CopyOnlyPrimeNumbers(Arr, Arr2, Length, Length2);

	cout << "Array elements: \n";
	PrintArray(Arr, Length);

	cout << "Prime Numbers in Array2 : \n";
	PrintArray(Arr2, Length2);


	return 0;
}