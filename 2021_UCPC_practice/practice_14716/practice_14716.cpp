#include <iostream>
using namespace std;

int m, n;
int ans = 0;
int banner[251][251];
bool visited[251][251];
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, -1, -1, 1 };

void dfs(int y, int x)
{
	visited[y][x] = true;
	for (int i = 0; i < 8; i++)
	{
		int checkX = x + dx[i];
		int checkY = y + dy[i];
		if (checkX < 0 || checkX >= n || checkY < 0 || checkY >= m)
			continue;
		if (banner[checkY][checkX] == 1 && visited[checkY][checkX] == 0)
		{
			visited[checkY][checkX]= 1;
			dfs(checkY, checkX);
		}
			
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

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (banner[i][j] == 1 && visited[i][j] == 0)
			{
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}

