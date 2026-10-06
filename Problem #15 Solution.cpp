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


void PrintLetterPattern(int Number)
{
	char Letter = 'A' + Number - 1;

	for (char i = 'A'; i <= Letter;  i++)
	{
		for (char j = 'A'; j <= i; j++)
		{
			cout << i;
		}
		cout << endl;
	}
}

//void PrintLetterPattern(int Number)//طريقة 2
//{
	//cout << "\n";

	//for (int i = 65; i <= 65 + Number - 1; i++)
	//{
		//for (int j = 1; j <= i - 65 + 1; j++)
		//{
			//cout << char(i);  
		//}

		//cout << "\n";  
	//}
//}
int main()
{
	PrintLetterPattern(ReadPositiveNumber("please enter a number?"));

	return 0;
}