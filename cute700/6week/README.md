# 2. 시리얼 번호
> 1차 접근 : 

### 정답

```cpp

```
- 
<br><br><br><br><br>

# 3. 이친수

> - 끝자리가 1일 때는 무조건 0이 와야하고 끝자리가 0일 떄는 0, 1 상관 없음.

### 정답

```cpp
#include <iostream>
using namespace std;

long long d[91];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	d[1] = 1;
	d[2] = 1;
	for (int i = 3; i <= n; i++)
		d[i] = d[i - 1] + d[i - 2];

	cout << d[n] << '\n';

	return 0;
}
```
- DP개념을 돌아보기 좋은 문제였습니다.
- 1차 스터디 이후 조금 쉬었지만 다시 화이텡...
<br><br><br><br><br>
