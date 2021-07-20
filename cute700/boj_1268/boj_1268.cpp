#include <iostream>

using namespace std;
// 임시 반장 정하기

int student[1000][5];
int studentCount[1000][1000] = { 0, };

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num;
	cin >> num;


	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 5; j++) // 학년
		{
			cin >> student[i][j];
		}
	}

	//for (int i = 0; i < num; i++)
	//{
	//	for (int j = 0; j < 5; j++) // 학년
	//	{
	//		cout << student[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < num - 1; j++)
		{
			for (int k = j + 1; k < num; k++)
			{
				if (k <= j)
					continue;
				else if (student[j][i] == student[k][i])
				{
					studentCount[j][k] = studentCount[k][j] = 1;
				}
			}
		}
	}


	return 0;
}