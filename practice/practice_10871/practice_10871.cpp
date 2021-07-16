#include <iostream>
using namespace std;

int main()
{
	int n, x, num;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num < x)
			cout << num << "\n";;
	}

	return 0;
}