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
#include <stack>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
#define fi first
#define se second
using namespace std;
int arr[200005];
pi num[100005];
int vis[100005];
int bit[200005];
const int N = 200005;
void add(int pos, ll value)
{
	while (pos <= N)
	{
		bit[pos] += value;
		pos += pos & -pos;
	}
}
ll sum(ll value)
{
	ll res = 0;
	while (value>0)
	{
		res += bit[value];
		value -= value & -value;
	}
	return res;
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i <= 2 * n; i++)
	{
		cin >> arr[i];
		if (!vis[arr[i]])
			num[arr[i]].fi = i;
		else
			num[arr[i]].se = i;
		vis[arr[i]] = 1;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += sum(num[i].se) - sum(num[i].fi);
		add(num[i].fi, 1);
		add(num[i].se, 1);
	}
	cout << ans;
}
