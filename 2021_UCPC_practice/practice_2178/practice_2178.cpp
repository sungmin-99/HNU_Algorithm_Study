#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int map[101][101];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf_s("%1d", map[i][j]);
	}
}