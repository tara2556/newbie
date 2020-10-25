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
#include <sstream>
#include <stack>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
#define fi first
#define se second
using namespace std;
int num1[150], num2[150], num3[150];
string Plus(string a, string b)
{
	string res;
	int ad = a.length();
	int bd = b.length();
	for (int i = ad - 1, j = 0; i >= 0; i--)
		num1[j++] = a[i] - '0';
	for (int i = bd - 1, j = 0; i >= 0; i--)
		num2[j++] = b[i] - '0';
	for (int i = 0; i < max(ad, bd); i++)
		num3[i] = num1[i] + num2[i];
	for (int i = 0; i < max(ad, bd) + 1; i++)
	{
		int t = num3[i] / 10;
		num3[i + 1] += t;
		num3[i] %= 10;
		res += num3[i] + '0';
	}
	reverse(res.begin(), res.end());
	if (res[0] == '0') res.erase(0, 1);
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	memset(num3, 0, sizeof(num3));
	return res;
}
string Cross(string a, string b)
{
	string res;
	int ad = a.length();
	int bd = b.length();
	for (int i = ad - 1, j = 0; i >= 0; i--)
		num1[j++] = a[i] - '0';
	for (int i = bd - 1, j = 0; i >= 0; i--)
		num2[j++] = b[i] - '0';
	for (int i = 0; i < ad; i++)
		for (int j = 0; j < bd; j++)
		{
			num3[j + i] += num1[i] * num2[j];
		}
	for (int i = 0; i < ad + bd; i++)
	{
		int t = num3[i] / 10;
		num3[i + 1] += t;
		num3[i] %= 10;
		res += num3[i] + '0';
	}
	reverse(res.begin(), res.end());
	if (res[0] == '0') res.erase(0, 1);
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	memset(num3, 0, sizeof(num3));
	return res;
}
string po[125];
string ans[125];
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	po[0] = "1";
	ans[0] = "1";
	for (int i = 1; i < n; i++)
	{
		po[i] = Cross(po[i - 1], "4");
		ans[i] = Plus(ans[i - 1], po[i]);
	}
	cout << ans[n - 1];
}
