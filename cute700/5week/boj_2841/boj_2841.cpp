#include <iostream>
#include <stack>
// 외계인의 기타연주
using namespace std;

int n, p, line, pNum, top;
stack<int> finger[7];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int result = 0;

	cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		cin >> line >> pNum;
		while (1)
		{
			if (finger[line].empty())
			{
				finger[line].emplace(pNum);
				result++;
				break;
			}
			top = finger[line].top();
			if (pNum == top) // 입력받은 프렛이 가장 높으면 냅두기
				break;
			else if (pNum > top) // 아닐 경우 스택 쌓고 카운트
			{
				finger[line].emplace(pNum);
				result++;
			}
			else // 입력받은 프렛이 작다면 가장 높은 프렛에서 손가락 떼기
			{
				finger[line].pop();
				result++;
			}
		}
	}
	cout << result << '\n';

	return 0;
}