#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, l;
	int arrayN[1001];
	int left;
	int tape = 1;

	cin >> n >> l;

	for (int i = 0; i < n; i++)
		cin >> arrayN[i];

	sort(arrayN, arrayN + n);
	left = arrayN[0];

	for (int i = 1; i <= n; i++)
	{
		if (arrayN[i] - left > l - 1)
		{
			left = arrayN[i];
			tape++;
		}
	}

	cout << tape;

	return 0;
}