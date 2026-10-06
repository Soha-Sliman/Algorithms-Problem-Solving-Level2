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

int MyCeil(float Num)
{
	if (Num > 0 && Num != int(Num))
		return int(Num) + 1;
	else
		return int(Num);
}


int main()
{
	float Num = ReadNumber();

	cout << "\nMy ceil result: " << MyCeil(Num) << endl;
	cout << "\nC++ ceil result: " << ceil(Num) << endl;

	return 0;
}