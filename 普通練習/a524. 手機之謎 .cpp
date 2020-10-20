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
#define pi pair<int,char>
#define mk make_pair
#define fi first
#define se second
using namespace std;
int num[9];
int ans[100005];
int it[9];
int visited[9];
int cnt = 0;
void dfs(int layer, int n)
{
	if (layer == n)
	{
		for (int i = 0; i < n; i++)
			ans[cnt] *= 10, ans[cnt] += it[i];
		cnt++;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visited[i]) continue;
		visited[i] = 1;
		it[layer] = i;
		dfs(layer + 1,n);
		visited[i] = 0;
	}
}
int po(int n)
{
	int res = 1;
	for (int i = 1; i <= n; i++)
		res *= i;
	return res;
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
			num[i - 1] = i;
		dfs(0, n);
		for (int i = po(n)-1; i >=0; i--)
			cout << ans[i] << '\n';
		memset(ans, 0, sizeof(ans));
		memset(visited, 0, sizeof(visited));
		memset(it, 0, sizeof(it));
		memset(num, 0, sizeof(num));
		cnt = 0;
	}
}
