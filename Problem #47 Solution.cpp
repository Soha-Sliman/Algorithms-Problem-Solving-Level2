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


float GetFractionPart(float Num)
{
	return Num - int(Num);
}


int MyRound(float Num)
{
	int IntPart = int(Num);

	float FractionPart = GetFractionPart(Num);

	if (abs(FractionPart) >= .5)
	{
		if (Num > 0)
			return ++IntPart;
		else
			return --IntPart;
	}
	else
	{
		return IntPart;
	}
}


int main()
{
	float Num = ReadNumber();

	cout << "\nMy round result: " << MyRound(Num) << endl;
	cout << "\nC++ round result: " << round(Num) << endl;

	return 0;
}