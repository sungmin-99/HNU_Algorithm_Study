# 3. 나무 자르기
> 1차 접근 : 실패
1. 같은 나무를 더 자를 수도 있다고 하고 
2. n개의 나무가 있고, n일 산에 오른다고 하여 
n일 동안 하루에 가장 긴 나무만 자르면 되지 않을까? 생각
결국 예제도 성립되지 못함 (56으로 정답 64에 미치지 못함)

누적 값이 가장 큰 나무를 가장 나중에 자르면 n일 잘랐을 때 가장 큰 값이 나올 것으로 예상
### 정답

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
```
