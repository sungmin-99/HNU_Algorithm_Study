#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, l;

	cin >> n >> l;

	int* h = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}

	sort(h, h + n);

	for (int i = 0; i < n; i++)
	{
		if (l >= h[i])
			l++;
		else
			continue;
	}

	cout << l;
	delete[] h;

	return 0;
}