#include <iostream>
using namespace std;
// ÃÖ´ñ°ª

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int arr[9];
	int max;

	for (int i = 0; i < 9; i++)
		cin >> arr[i];

	max = arr[0];

	for (int i = 1; i < 9; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	for (int i = 0; i < 9; i++)
	{
		if (max == arr[i])
			cout << max << "\n" << i + 1;
	}

	return 0;
}
