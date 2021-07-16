#include <iostream>
using namespace std;
// 최대, 최소

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = 1000000, min, max;
	int temp;
	int* num = new int[n];

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> num[i];
	min = num[0];
	max = num[0];

	for (int i = 1; i < n; i++)
	{
		if (num[i] < min)
		{
			min = num[i];
		}
		else if (num[i] > max)
		{
			max = num[i];
		}
	}
	cout << min<< ' ' << max;

	delete[] num;
	return 0;
}