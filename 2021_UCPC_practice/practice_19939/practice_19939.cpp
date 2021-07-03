#include <iostream>
using namespace std;

// ¹Ú ÅÍ¶ß¸®±â

int main()
{
	int n, k;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	int min = (k + 1) * k / 2;  

	if (n < min)
		cout << -1;
	else if ((n - min) % k == 0)
		cout << k - 1;
	else
		cout << k;

	return 0;
}