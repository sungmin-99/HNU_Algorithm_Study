#include <iostream>
#include <string.h>
using namespace std;

int n, m;
bool map[50][50];
bool visited[50][50];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool dfs(int x, int y);

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t, k;  // t = 농장, k = 배추 개수 (농장별로 입력)
	cin >> t;

	while (t--)
	{
		cin >> n >> m >> k;  // 세로, 가로, 배추 심어진 개수
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			map[x][y] = true;
		}

		int worm = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] && !visited[i][j])
				{
					dfs(i, j);
					worm++;
				}
			}
		}
		cout << worm << '\n';

	}
	return 0;
}

bool dfs(int x, int y)
{
	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int checkX = x + dx[i];
		int checkY = y + dy[i];
		if (x <= -1 || x >= n || y <= -1 || y >= m)
			return false;
		if (map[checkX][checkY] && !visited[checkX][checkY])
			dfs(checkX, checkY);
	}

}