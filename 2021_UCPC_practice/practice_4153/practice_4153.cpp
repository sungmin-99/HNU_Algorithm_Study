#include <iostream>
using namespace std;

int main()
{
	long side1, side2, side3;

	while (1)
	{
		long num1, num2, num3;

		cin >> side1 >> side2 >> side3;
		if (side1 == 0 && side2 == 0 && side3 == 0)
			break;

		num1 = side1 * side1;
		num2 = side2 * side2;
		num3 = side3 * side3;

		if (num1 + num2 == num3 || num1 + num3 == num2 || num2 + num3 == num1)
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
	return 0;
}