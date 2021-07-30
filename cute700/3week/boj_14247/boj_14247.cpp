#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 나무 자르기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	long long result = 0;
	int h, a;
	cin >> n;

	vector<pair<int, int>> tree(n);

	for (int i = 0; i < tree.size(); i++)
	{
		cin >> tree[i].second; // 첫 번쨰 나무 길이
	}
	for (int i = 0; i < tree.size(); i++)
	{
		cin >> tree[i].first; // 하루에 자라는 길이
	}
	sort(tree.begin(), tree.end());  // first 값을 정렬해야하므로 하루에 자라는 길이를 first에 넣음

	for (int i = 0; i < n; i++)
	{
		result += tree[i].first * i + tree[i].second; // i 곱하는 이유는 지금까지 자르지 않고 더해진 길이를 나타내기 위함, second는 첫번 째 값 더해주는 역할
	}

	cout << result;

	return 0;
}