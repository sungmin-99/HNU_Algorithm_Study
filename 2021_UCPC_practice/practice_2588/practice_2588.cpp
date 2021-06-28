#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	cin >> num1;
	cin >> num2;

	cout << num1 * ((num2 - (num2 / 100) * 100) - (((num2 - (num2 / 100) * 100) / 10) * 10)) << endl;
	cout << num1 * ((num2 - (num2 / 100) * 100) / 10) << endl; //4
	cout << num1 * (num2 / 100) << endl; //5
	cout << num1 * num2; //6
	return 0;
}