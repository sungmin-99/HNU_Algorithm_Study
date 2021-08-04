# 1. 적녹 색약
> 1차 접근 : 먼저 문제를 보자마자 dfs가 가능하겠구나 생각이듬. dfs를 r, g, b, rg (총 4개)를 만들어 방문처리 없이 하려고 생각함. 
> <br> 
> 이 방법은 아무리 생각해도 너무 비효율적인거 같아 dfs 하나와 방문처리를 이용해 코드를 줄여보고자 함

### 정답

```cpp
#include <iostream>
#include <string.h>

using namespace std;
// 적록색약

int n;
char arr[101][101];
bool visited[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y)
{

	visited[x][y] = true;
	if (x < 0 || x > 100 || y < 0 || y > 100)
		exit(0);
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!(visited[nx][ny]) && (arr[x][y] == arr[nx][ny])) // 방문 하지 않았고, 먼저 값과 값이 같다면 dfs
		{
			dfs(nx, ny);
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
				resultNormal++;
			}
		}
	}
	memset(visited, false, sizeof(visited)); //적록 색약의 경우를 검사하기 위해 앞서 방문 처리해 준걸 초기화
	
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

	cout << resultNormal << ' ' << resultRG << endl;
	return 0;
}
```
<b> dfs 함수에서 방문처리 부분과 (x, y)는 (nx, ny)(4 방향)과 같다는 것 만 증명해주고 <br>
정상의 경우, 색약의 경우 반복문을 나눠서 계산해주면 되는 문제
<br><br>
<b> 아직도 맞왜틀이 많이 나오는데 이 문제의 경우 `memset`을 위해 처음엔 `cstring` 헤더를 사용했는데 틀리길래 `string.h`를 사용했더니 맞았다고 뜸. 
	<br> c++ 버전 문제인지, 원인을 아직 찾지 못함. (원래 cstring이 c언어의 string.h를 c++에서 호환되도록 만든 파일이라고 알고 있었습니다만...)
<br><br><br><br><br>
