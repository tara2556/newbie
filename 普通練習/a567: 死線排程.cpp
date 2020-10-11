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
#include <cstdlib>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
using namespace std;
int dead[10005], profit[10005], num[10005];
bool cmp(int a, int b)
{
	return dead[a] < dead[b];
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	while (cin >> n)
	{
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> dead[i] >> profit[i];
			num[i] = i;
		}
		sort(num, num + n, cmp);
		priority_queue<int,vector<int>,greater<int>> p;
		for (int i = 0; i < n; i++)
		{
			if (dead[num[i]] > p.size())
			{
				ans += profit[num[i]];
				p.push(profit[num[i]]);
			}
			else if (dead[num[i]] == p.size()&&profit[num[i]] > p.top())
			{
				ans -= p.top();
				p.pop();
				ans += profit[num[i]];
				p.push(profit[num[i]]);
			}
		}
		cout << ans << '\n';
		memset(dead, 0, sizeof(dead));
		memset(profit, 0, sizeof(profit));
		memset(num, 0, sizeof(num));
	}
}
