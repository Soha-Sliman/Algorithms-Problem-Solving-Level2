#include <iostream>
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

void PrintInvertedLetterPattern(int Number)
{
	char Letter = 'A' + Number - 1;
	for (char i = Letter; i >= 'A'; i--)
	{
		for (char j = 'A'; j <= i; j++)
		{
			cout << i;
		}
		cout << "\n";
	}
}

//void PrintInvertedLetterPattern(int Number)//طريقة 2
//{
//   for(int i = 65 + Number - 1; i >=65; i++;
//   {
//       for(int j = 1; j <= Number - (65 + Number - 1 - i); j++)
//       {
//            cout << char(i);
//       }
//       cout << "\n";
//   }
//}


int main()
{
	PrintInvertedLetterPattern(ReadPositiveNumber("please enter a positive number?"));
	return 0;
}