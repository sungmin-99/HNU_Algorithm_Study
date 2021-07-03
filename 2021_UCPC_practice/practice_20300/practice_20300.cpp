#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, t;
	int m;
	cin >> n;

	int* arrayN = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> t;
		arrayN[i] = t;
	}
	sort(arrayN, arrayN + n);

	if (n % 2 == 0)
	{
		m = arrayN[0] + arrayN[n - 1];
		for (int i = 1; i < n / 2; i++)
			m = max(m, arrayN[i] + arrayN[n - 1 - i]);
	}
	else
	{
		m = arrayN[n - 1];
		for (int i = 0; i < (n - 1) / 2; i++)
			m = max(m, arrayN[i] + arrayN[n - 2 - i]);
	}
	cout << m;

	delete[] arrayN;

	return 0;
}