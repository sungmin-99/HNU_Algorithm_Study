#include <iostream>
#include <string>
using namespace std;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int first = 0, last = 0;

	int num, count = 0;
	int all = 0;

	cin >> num;
	all = num;
	while (num > 0)
	{
		count++;
		num /= 10;
	}
	int* arr = new int[count];

	for (int i = 0; i < count; i++)
	{
		arr[i] = all % 10;
		all /= 10;
	}

	if (arr[0] == arr[1] + 1)
	{
		last = arr[0];
	}

	if (arr[count - 1] == arr[count - 2] - 1)
		first = arr[count - 1];

	cout << first << ' ' << last;

}



//for (int i = 0; i < 2889; i++)
//	scanf_s("%id", &input[i]);

