#include "pch.h"
#include <iostream>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int n, bit[100005];
int lowbit(int x)
{
	return x & -x;
}
inline void update(int i)
{
	while (i <= n)
	{
		bit[i]++;
		i += lowbit(i);
	}
}

inline int query(int i)
{
	int res = 0;
	while (i)
	{
		res += bit[i];
		i -= lowbit(i);
	}
	return res;
}
main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int t = 1;
	while (cin >> n&&n)
	{
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			bit[i] = v[i];
		}
		sort(bit, bit + n);
		for (int i = 0; i < n; i++)
		{
			v[i] = lower_bound(bit, bit + n, v[i]) - bit + 1;
		}
		memset(bit, 0, sizeof(bit));
		int a = 0, ans = 0;
		for (auto p : v)
		{
			ans += a - query(p);
			update(p);
			a++;
		}
		cout <<"Case #"<<t++<<": "<< ans << '\n';
	}
}
