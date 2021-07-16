#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 뒤집기

int main()
{
	string s;
	int length, zeroCount = 0, oneCount = 0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;

	if (s[0] == '0')
		zeroCount++;
	else
		oneCount++;

	length = s.length();
	for (int i = 1; i < length; i++)
	{
		if (s[i] != s[i - 1]) // 현재 문자와 이전문자가 다르면 한 번만 카운트 해주면 됨
		{
			if (s[i] == '0')
				zeroCount++;
			else
				oneCount++;
		}
	}
	cout << min(zeroCount, oneCount);

	return 0;
}