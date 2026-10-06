#include<iostream>
#include<string>

using namespace std;

void PrintWordsFromAAAtoZZZ()
{
	string Word = "";

	for (char i = 'A'; i <= 'Z'; i++)
	{
		for (char j = 'A'; j <= 'Z'; j++)
		{
			for (char k = 'A'; k <= 'Z'; k++)
			{
				//Word += i;
				Word.append(1, i);
				//Word += j;
				Word.append(1, j);
				//Word += k;
				Word.append(1, k);

				cout << Word << endl;

				Word = "";
			}
		}
		cout << "\n----------------\n";
	}
}

int main()
{
	PrintWordsFromAAAtoZZZ();

	return 0;
}

