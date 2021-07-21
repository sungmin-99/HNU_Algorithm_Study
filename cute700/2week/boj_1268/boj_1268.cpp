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

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
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
	cout << captain;

	//for (int i = 0; i < num; i++) // 학생 별로 몇명이랑 같은 반이었는지 카운트 보기
	//{
	//	cout << studentCount[i] << ' ';
	//}

	return 0;
}