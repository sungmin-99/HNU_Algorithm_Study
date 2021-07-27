1차 시도 : 실패
#include <iostream>
using namespace std;
// 상자의 균형

int main()
{
	int n;
	long long l, sum = 0, ave;

	cin >> n >> l;

	long long* center = new long long[n];

	for (int i = 0; i < n; i++)
	{
		cin >> center[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (n == 2)
		{
			sum = center[1];
			break;
		}
		sum += center[i + 1];
	}

	ave = sum / (n - 1);
	
	if (ave < center[0] + l && ave > center[0] - l)
		cout << "stable";
	else
		cout << "unstable";

	delete[] center;

	return 0;
}