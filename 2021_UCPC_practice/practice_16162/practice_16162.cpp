#include <iostream>
using namespace std;

// 3´Ü°íÀ½

int main()
{
	int n, a, d, num;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> a >> d;

	int now = a, count = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num == now)
		{
			count++;
			now += d;
		}
	}
	cout << count;

	return 0;
}