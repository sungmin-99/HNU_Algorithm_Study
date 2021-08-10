#include <iostream>
using namespace std;
// 토너먼트

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, kim, lim;
	int cnt = 0;

	cin >> n >> kim >> lim;

	if (n < kim || n < lim)
		cnt = -1;
	else 
	{
		while (kim != lim)
		{
			kim = (kim + 1) / 2;
			lim = (lim + 1) / 2;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}