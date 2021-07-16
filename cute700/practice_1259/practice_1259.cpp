#include <iostream>
using namespace std;

int main()
{
	while (1)
	{
		int num;
		int rnum = 0;
		cin >> num;
		if (num == 0)
			break;

		int temp = num;

		while (num > 0)
		{
			rnum *= 10;
			rnum += (num % 10);
			num /= 10;
		}

		if (temp == rnum)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}