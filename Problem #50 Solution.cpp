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


float MySqrt(float Num)
{
	return pow(Num, 0.5);
}


int main()
{
	float Num = ReadNumber();

	cout << "\nMy sqrt result: " << MySqrt(Num) << endl;
	cout << "\nC++ sqrt result: " << sqrt(Num) << endl;

	return 0;
}