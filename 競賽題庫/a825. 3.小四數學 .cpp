#include <pch.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define pi pair
#define mk make_pair
using namespace std;
int num[10];
string ans1, ans2;
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	int x = 0, y = 0;
	sort(num, num + n);
	for (int i = n - 1; i >= 0; i--)
	{
		if (x <= y)
		{
			x *= 10;
			x += num[i];
		}
		else
		{
			y *= 10;
			y += num[i];
		}
	}
	cout << x * y;
}
