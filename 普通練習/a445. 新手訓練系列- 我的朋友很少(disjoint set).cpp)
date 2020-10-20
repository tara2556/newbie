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
int f[1000006];
int s[1000006];
inline void init(int n)
{
	for (int i = 0; i <= n; i++)
		f[i] = i, s[i] = 1;
}
inline int find(int x)
{
	return x == f[x] ? x : f[x] = find(f[x]);
}
inline bool same(int a, int b)
{
	return find(a) == find(b);
}
inline void unite(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return;
	if (s[a] < s[b]) swap(a, b);
	f[b] = a, s[a] += s[b];
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n, m, q;
	cin >> n >> m >> q;
	init(n);
	for (int i = 0; i < m; i++)
	{
		int k1, k2;
		cin >> k1 >> k2;
		unite(k1, k2);
	}
	for (int i = 0; i < q; i++)
	{
		int k1,k2;
		cin >> k1 >> k2;
		if (same(k1, k2))
			cout << ":)" << '\n';
		else
			cout << ":(" << '\n';
	}
}
