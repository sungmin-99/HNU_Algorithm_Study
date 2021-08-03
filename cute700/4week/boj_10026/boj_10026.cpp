#include <iostream>
#include <vector>

using namespace std;
// 적록색약

int n;
char arr[100][100];
bool visited[100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y)
{

	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny <= 100 && nx >= 0 && nx <= 100)
		{
			if (!(visited[nx][ny]) && (arr[x][y] == arr[nx][ny]))
			{
				dfs(nx, ny);
			}
		}
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	// 배열에 r, g, b 넣기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	// rgb 영역 검사
	int resultNormal = 0;
	int resultRG = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				dfs(i, j);
				resultNormal += 1;
			}
		}
	}
	memset(visited, false, sizeof(visited)); //적록 색약 검사를 위해 방문처리된걸 초기화

	// r과 g를 같이 인식하므로 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 'R')
				arr[i][j] = 'G';
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				dfs(i, j);
				resultRG++;
			}
		}
	}

	cout << resultNormal << ' ' << resultRG;

}