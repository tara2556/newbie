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
#define ll long long
#define pi pair<ll,ll>
#define mk make_pair
using namespace std;
pi f[100005];
bool cmp(pi a, pi b)
{
	return (a.first*b.second) < (a.second*b.first);
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> f[i].first;
	for (int i = 0; i < n; i++)
		cin >> f[i].second;
	sort(f, f + n, cmp);
	ll cnt = 0, cnt2 = 0;
	for (int i = 0; i < n - 1; i++)
	{
		cnt += f[i].first;
		cnt2 += cnt * f[i + 1].second;
	}
	cout << cnt2;
}
