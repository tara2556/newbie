#include "pch.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> p[100005];
int cunt[100006];
long long int ans, ans2, cnt, maxn;
void dfs(int n)
{
	if (p[n].empty())
		cunt[n] = 0;
	else
	{
		int mx = 0;
		for (auto i : p[n])
		{
			dfs(i);
			mx = max(mx, cunt[i] + 1);
		}
		cunt[n] = mx;
	}
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	fill(cunt, cunt + n, 1);
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int t;
			cin >> t;
			t--;
			p[i].push_back(t);
			cunt[t] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (cunt[i])
		{
			ans = i;
			break;
		}
	}
	memset(cunt, 0, sizeof(cunt));
	dfs(ans);
	for (int i = 0; i < n; i++)
		ans2 += cunt[i];
	cout << ans+1 << '\n' << ans2;
}
