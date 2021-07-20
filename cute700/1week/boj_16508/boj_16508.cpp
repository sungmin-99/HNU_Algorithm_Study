#include <iostream>
#include <string>
using namespace std;
// Àü°øÃ¥


int main()
{
	string text;
	int num = 0;

	cin >> text;
	cin >> num;

	int* cash = new int[num];
	char* word = new char[num];

	for (int i = 0; i < num; i++)
	{
		cin >> cash[i] >> word[i];
	}

	return 0;

}