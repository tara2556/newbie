#include <pch.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <unordered_map>
#include <vector>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
using namespace std;
unordered_map<string, int> mp;
string a[200005];
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int m, n;
	cin >> m >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++)
	{
		if (!mp[a[i]]) cnt++;
		mp[a[i]]++;
	}
	int ans = (cnt == m);
	for (int L = 0, R = m; R < n; L++, R++)
	{
		mp[a[L]]--;
		if (!mp[a[L]]) cnt--;
		if (!mp[a[R]]) cnt++;
		mp[a[R]]++;
		ans += (cnt == m);
	}
	cout << ans;
}
