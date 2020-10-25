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
int red[10005];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	while (cin >> n)
	{
		int cnt = 0;
		while (cin >> red[cnt] && red[cnt] != -1)
		{
			cnt++;
		}
		sort(red, red + cnt, cmp);//排序
		ll ans = 0;
		for (int i = 0; i < min(n, cnt); i++)//最多只能拿全部紅包
		{
			ans += red[i];
		}
		cout << ans << '\n';
	}
	memset(red, 0, sizeof(red));//初始化
}
