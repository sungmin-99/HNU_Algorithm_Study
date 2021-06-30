#include <iostream>
using namespace std;

// 문자열로도 풀어보기

int main()
{
	int n, left, right, addedRight;
	int count = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int tmp = n;

	while (1)
	{
		left = n / 10;
		right = n % 10;
		addedRight = (left + right) % 10;

		n = (right * 10) + addedRight;

		count++;
		if (tmp == n)
			break;
	}
	cout << count;

	return 0;
}