#include <iostream>
#include <string>
using namespace std;
// 숫자의 개수
// 아직 푸는 중

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	int total;
	int num0 = 0, num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0, num8 = 0, num9 = 0;
	string strTotal;

	cin >> a >> b >> c;

	total = a * b * c;

	strTotal = to_string(total);
	cout << strTotal << "\n";

	for (int i = 0; i < strTotal.length(); i++)
	{
		
	}
	cout << num0 << "\n";
	cout << num1 << "\n";
	cout << num2 << "\n";
	cout << num3 << "\n";
	cout << num4 << "\n";
	cout << num5 << "\n";
	cout << num6 << "\n";
	cout << num7 << "\n";
	cout << num8 << "\n";
	cout << num9 << "\n";
}
