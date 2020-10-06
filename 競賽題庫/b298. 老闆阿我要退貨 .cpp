#include <pch.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
using namespace std;
vector<int> p[10005];
int que[10005];
void dfs(int n)
{
	que[n] = 1;
	for (auto i : p[n])
	{
		if (!que[i])
			dfs(i);
	}
}
int main()
{
	int n, m, l, q;
	cin >> n >> m >> l >> q;
	for (int i = 0; i < m; i++)
	{
		int k1, k2;
		cin >> k1 >> k2;
		p[k1].push_back(k2);
	}
	for (int i = 0; i < l; i++)
	{
		int k1;
		cin >> k1;
		dfs(k1);
	}
	for (int i = 0; i < q; i++)
	{
		int k1;
		cin >> k1;
		if (que[k1])
			cout << "TUIHUOOOOOO" << '\n';
		else
			cout << "YA~~" << '\n';
	}
}
