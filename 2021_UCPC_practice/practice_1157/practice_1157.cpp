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

//	while (1)
//{
//	string data;
//	cin >> data;
//	if (data == "0")
//		break;
//
//	bool isTrue = true;
//	for (int i = 0; i < data.size() / 2; i++)
//	{
//		if (data[i] != data[data.size() - i - 1])
//			isTrue = false;
//		break;
//	}
//
//	if (isTrue)
//		cout << "yes" << endl;
//	else
//		cout << "no" << endl;
//}
//
//return 0;