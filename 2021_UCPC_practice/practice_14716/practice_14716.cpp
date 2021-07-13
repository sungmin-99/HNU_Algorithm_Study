#include <iostream>
using namespace std;

int m, n;
int ans = 0;
bool banner[250][250];
bool visited[250][250];
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, -1, -1, 1 };

void dfs(int x, int y)
{
	visited[x][y] = true;
	for (int i = 0; i < 8; i++)
	{
		int checkX = x + dx[i];
		int checkY = y + dy[i];
		if (checkX < 0 || checkX >= n || checkY < 0 || checkY >= m)
			continue;
		if (banner[checkX][checkY] && !visited[checkX][checkY])
			dfs(checkX, checkY);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> banner[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (banner[i][j] == 1 && !visited[i][j])
			{
				ans++;
				dfs(i, j);
			}
		}
	}
	cout << ans;
	return 0;
}

