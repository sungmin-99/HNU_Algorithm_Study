#include <iostream>
using namespace std;
// 유기농 배추

int n, m;
bool map[51][51];
bool visited[51][51];
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
				if (map[j][i] && !visited[j][i])
				{
					dfs(j, i);
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
	visited[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int checkX = x + dx[i];
		int checkY = y + dy[i];
		if (checkX < 0 || checkX >= n || checkY < 0 || checkY >= m)
			return false;
		if (map[checkY][checkX] && !visited[checkY][checkX])
			dfs(checkY, checkX);
	}

}