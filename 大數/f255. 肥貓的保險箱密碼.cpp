#include <pch.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
using namespace std;
int num1[5000], num2[5000], num3[10000];
string po(string a,string b)
{	
	string ans;
	int d1 = a.length();
	int d2 = b.length();
	for (int i = d1 - 1, j = 0; i >= 0; i--)
		num1[j++] = a[i] - '0';
	for (int i = d2 - 1, j = 0; i >= 0; i--)
		num2[j++] = b[i] - '0';
	for (int i = 0; i < d1; i++)
		for (int j = 0; j < d2; j++)
		{
			num3[i + j] += num1[i] * num2[j];
		}
	for (int i = 0; i < d1+d2+2; i++)
	{
		if (num3[i] >= 10)
		{
			num3[i + 1] += num3[i] / 10;
			num3[i] %= 10;
		}
	}
	for (int i = 0; i < d1+d2; i++)
	{
		ans += num3[i] + '0';
	}	
	reverse(ans.begin(), ans.end());
	if (ans[0] == '0') ans.erase(0, 1);
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	memset(num3, 0, sizeof(num3));
	return ans;
}
string ans[10002];
void AC()
{
	ans[1] = "2";
	for (int i = 2; i <= 10000; i++)
		ans[i] = po("2", ans[i-1]);
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	AC();
	while (cin >> n && n)
	{
		cout << ans[n]<< '\n';
	}
}
