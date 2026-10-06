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

int MyFloor(float Num)
{
	if (Num > 0 || Num == int(Num))
		return int(Num);
	else
		return int(Num) - 1;
}


int main()
{
	float Num = ReadNumber();

	cout << "\nMy floor result: " << MyFloor(Num) << endl;
	cout << "\nC++ floor result: " << floor(Num) << endl;

	return 0;
}