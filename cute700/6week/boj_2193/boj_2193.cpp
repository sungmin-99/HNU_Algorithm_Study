#include <iostream>
using namespace std;

long long d[91];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	d[1] = 1;
	d[2] = 1;
	for (int i = 3; i <= n; i++)
		d[i] = d[i - 1] + d[i - 2];

	cout << d[n] << '\n';

	return 0;
}