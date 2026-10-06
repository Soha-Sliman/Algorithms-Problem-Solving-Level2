#include<iostream>
#include<string>

using namespace std;

string ReadPassword()
{
	string Password;

	cout << "please enter a 3-letters password?\n";
	cin >> Password;

	return Password;
}

bool GuessPassword(string CheckPassword)
{
	string Word = "";
	int count = 0;
	for (char i = 'A'; i <= 'Z'; i++)
	{
		for (char j = 'A'; j <= 'Z'; j++)
		{
			for (char k = 'A'; k <= 'Z'; k++)
			{
				count++;

				Word.append(1, i);
				Word.append(1, j);
				Word.append(1, k);

				cout << " Trial[" << count << "]:  " << Word << endl;

				if (CheckPassword == Word)
				{
					cout << "Password is " << Word << endl;
					cout << "Found after " << count << "  trial(s)\n";
					return true;
				}
				Word = "";
			}
		}
		
	}
	return false;
}

int main()
{
	GuessPassword(ReadPassword());

	return 0;
}