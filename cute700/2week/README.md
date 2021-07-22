# 1. 임시 반장 정하기
> 처음 접근 방식
- 한 학생에 대해 한 학년을 다른학생의 학년과 비교해가는 방식을 생각했음.
<b>이 방식을 넘긴 이유 : 학생들끼리 같은 반이 여러번 이었던 경우에 한 번으로 처리 해줘야하는데 그 부분 구현이 계속해서 막혔음 </b>
```{.no-highlight}
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < num - 1; j++)
        {
            for (int k = 0; k < num; k++)
            {
                if (k == j)
                    continue;
                else if (student[j][i] == student[k][i])
                {
                    studentCount[j][k] = studentCount[k][j] = 1;
                }
            }
        }
    }
```
<br>

> 1차시도
```cpp
#include <iostream>

using namespace std;
// 임시 반장 정하기

int student[1000][5];
int studentCount[1000];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
		studentCount[i] = 0;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 5; j++) // 학년
		{
			cin >> student[i][j];
		}
	}

	for (int i = 0; i < num; i++) // 지정한 학생
	{
		for (int j = 0; j < num; j++) // 비교할 학생
		{
			for (int k = 0; k < 5; k++)
			{
				if (student[i][k] == student[j][k])
				{
					studentCount[i]++;
					break;
				}
			}
		}
	}

	int max = 0; // 초기 최대값 저장
	int captain = 0; 
	for (int i = 0; i < num; i++)
	{
		if (max < studentCount[i])
		{
			max = studentCount[i];
			captain = i + 1;
		}
		else if (studentCount[i] == max)
			if (captain > i)
				captain = i + 1;
	}
	cout << captain << endl;
	return 0;
}
```
<br>
한 학생에 대해 다른 학생과 모든 학년을 비교하여 같은 값을 찾음. <br>
같은 값을 찾고 break 해주어 처음 접근했던 방식의 문제 (정 학생들끼리 같은 반이 여러번 이었던 경우)를 해결 할 수 있었음.<br>

<b>정답이 맞긴 했으나 학생별 최댓값을 출력해보니 나와야할 값보다 하나씩 더 나오는 경우가 있었음 </b>
<br><br><br><br><br><br>

> 정답
```cpp
#include <iostream>

using namespace std;
// 임시 반장 정하기

int student[1000][5];
int studentCount[1000];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
		studentCount[i] = 0;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 5; j++) // 학년
		{
			cin >> student[i][j];
		}
	}

	for (int i = 0; i < num; i++) // 지정한 학생
	{
		for (int j = 0; j < num; j++) // 비교할 학생
		{
			for (int k = 0; k < 5; k++)
			{
				if (i == j) // 자신과 비교할 경우 건너뜀
					break;
				if (student[i][k] == student[j][k])
				{
					studentCount[i]++;
					break;
				}
			}
		}
	}

	int max = 0; // 초기 최대값 저장
	int captain = 0; 
	for (int i = 0; i < num; i++)
	{
		if (max < studentCount[i])
		{
			max = studentCount[i];
			captain = i + 1;
		}
		else if (studentCount[i] == max)
			if (captain > i)
				captain = i + 1;
	}
	cout << captain << endl;

	return 0;
}
```
<br>

    if (i == j) 
    break;

<b>위 조건을 걸어주어 자신과 비교한 경우는 없애줌. <b><br>
<br><br><br><br><br><br>
