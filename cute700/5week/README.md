# 3. 토너먼트
> 1차 접근 : 아이디어 구현부터 삽질을 했습니다.. 
> <br> 
> - 김지민과 임한수 (편의상 kim과 lim으로 부르겠습니다.) 
> - 각자의 번호에서 /2를 해주고 %2를 해준값을 더해 카운트를 해야하나 생각들었습니다. (지금 생각해보니 이것도 맞는거 같은데 당시엔 본질을 파악하지 못했습니다.)
> - 부전승도 처리해야할 생각에 막막했습니다.

### 정답

```cpp
#include <iostream>
using namespace std;
// 토너먼트

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, kim, lim;
	int cnt = 0;

	cin >> n >> kim >> lim;

	if (n < kim || n < lim)
		cnt = -1;
	else 
	{
		while (kim != lim)
		{
			kim = (kim + 1) / 2;
			lim = (lim + 1) / 2;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}
```
- 참가자 수 보다 kim과 lim의 번호가 큰 경우는 패스합니다.
- 무조건 kim과 lim은 이긴다고 가정하기에 kim과 lim이 다르면 계속해서 반복해줍니다.
- 각각 +1을 해준 후 2를 나눠주면 다음 라운드 번호가 주어집니다. 
- <b>참가자수가 홀수인 경우 부전승이 발생하는데 이는 영향을 미치지 않습니다.</b> (이 부분 생각하기가 쉽지 않았습니다.)
- 항상 이기기 때문에 다음 라운드 번호만 구해주면 쉽게 아이디어를 구현할 수 있습니다.
<br>
- 아직 좀 더 문제들을 많이 풀어봐야할 것 같습니다. 익숙해지기!
<br><br><br><br><br>

# 4. 외계인의 기타 연주
> 1차 접근 : 스택 문제인걸 알고 풀었기에 수월했습니다.
> <br> 
> - 처음엔 지금까지 스택처럼 사용해오던 `<vector>` 컨테이너를 사용하려고 했으나 구글링을 통해 가독성을 위해 `<stack>` 컨테이너를 사용했습니다.
> - 멜로디와 프렛을 모두 입력받고 연산을 하는 방법과 한 번 멜로디와 프렛을 입력받고 하나씩 비교하며 넘어가는 방법이 있다고 생각들었습니다.

### 정답

```cpp
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
```
- `while(1)`에서 멜로디에 처음 넣어주거나 프렛이 가장 높을 경우에만 탈출 해주면 됩니다. 
- 새로 손가락을 누를 때 혹은 프렛이 기존 top 보다 높거나 작을 때 카운트를 해줍니다. 다만 프렛이 top보다 작은 경우는 pop을 해줍니다.  

+ `<stack>`도 pair를 이용해 한 쌍씩 묶을 수 있는데 그냥 stack 6개(기타 줄)를 사용한 것 과 비교하여 
+ pair사용 시 2020kb, 84ms, 965B가 나왔고
+ 그냥 stack을 사용하는 경우는 2020kb, 88ms, 648B가 나왔습니다. 
+ 좀 더 코드도 줄이면서 연산속도도 빠른 코드를 생각해 보면 좋을 것 같습니다. 
