#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int getSum(string a);
bool compare(string str1, string str2);

vector<string> v;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string str;
    for (int i = 0; i < n; i++) 
    {
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < n; i++)
        cout << v[i] << "\n";
}

bool compare(string str1, string str2)
{
    //길이가 짧은게 먼저
    if (str1.length() != str2.length()) 
    {
        return str1.length() < str2.length();
    }
    //길이 같을때
    else 
    {
        if (getSum(str1) != getSum(str2)) 
            return getSum(str1) < getSum(str2);
        else return str1 < str2;
    }
}

int getSum(string a)
{
    int n = a.length(), sum = 0;
    for (int i = 0; i < n; i++) 
    {
        if (a[i] - '0' <= 9 && a[i] - '0' >= 0) 
            sum += a[i] - '0';
    }
    return sum;
}