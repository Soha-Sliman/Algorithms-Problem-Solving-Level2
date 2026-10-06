#include<iostream>
#include<cmath>

using namespace std;


float ReadNumber()
{
	float Num;

	cout << "Please enter a number?";
	cin >> Num;
	return Num;
}

float MyABS(float Num)
{
	if (Num > 0)
		return  Num;
	else
		return Num * -1;
}


int main()
{
	float Num = ReadNumber();

	cout << "\nMy abs result: " << MyABS(Num) << endl;
	cout << "\nC++ abs result: " << abs(Num) << endl;

	return 0;
}