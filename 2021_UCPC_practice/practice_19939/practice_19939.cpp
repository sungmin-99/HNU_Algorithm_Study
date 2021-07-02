#include <iostream>
using namespace std;

// 박 터뜨리기

int main()
{
	int n, k, sum = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	if (n > 2 && k == 2)
	{                    // 위 조건에서 n이
		if (n % 2 == 0)  // 짝수면 무조건 2
			cout << 2;
		else             // 홀수면 무조건 1
			cout << 1;
		return 0;
	}

	for (int i = 1; i <= k; i++)
		sum += i;

	n -= sum;



	return 0;
}