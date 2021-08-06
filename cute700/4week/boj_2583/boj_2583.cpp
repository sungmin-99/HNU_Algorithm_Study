#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 영역 구하기

int arr[101][101];
bool visited[101][101];
int m, n, k;
int cnt;
vector<int> areaCount;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y)
{
	int nx, ny;

	visited[x][y] = true;
	cnt++;

	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny])
		{
			dfs(nx, ny);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> k;  // y, x, 직사각형 개수

	for (int i = 0; i < k; i++) // 좌표 입력 (좌하단, 우상단)
	{
		int xLeft, yLeft, xRight, yRight;

		cin >> xLeft >> yLeft >> xRight >> yRight;
		for (int j = yLeft; j < yRight; j++)
		{
			for (int k = xLeft; k < xRight; k++)
			{
				arr[j][k] = 1;
				visited[j][k] = true;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0 && visited[i][j] == false)
			{
				cnt = 0;
				dfs(i, j);
				areaCount.emplace_back(cnt);
			}
		}
	}

	sort(areaCount.begin(), areaCount.end());
	int size = areaCount.size();

	cout << size << '\n';
	for (int i = 0; i < size; i++)
		cout << areaCount[i] << ' ';;

	return 0;
}