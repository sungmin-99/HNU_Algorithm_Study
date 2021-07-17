#include <iostream>
#include <queue>
using namespace std;
// 미로 탐색

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int map[101][101];
int visited[101][101];
int n, m;

int bfs(int x, int y)
{
	visited[x][y] = 1;
	queue <pair <int, int> > q;
	q.push(make_pair(x, y));

	while (q.empty() == false)
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (map[nextX][nextY] == 0) // 벽인 경우 무시
				continue;
				

		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf_s("%1d", map[i][j]);
	}

	bfs(0, 0);
}