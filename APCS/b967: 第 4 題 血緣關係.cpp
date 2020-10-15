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
#define pi pair<int,int>
#define mk make_pair
using namespace std;
vector<int> p[100005];
int visited[100005];
int ans;
void dfs(int n,int k)
{
	for (int i : p[n])
	{
		if (i!=k)
		{
			visited[i] = visited[n] + 1;
			dfs(i, n);
		}
	}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	int cnt = 0;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			p[i].clear();
		for (int i = 0; i < n-1; i++)
		{
			int k, k1;
			cin >> k >> k1;
			p[k].push_back(k1);
			p[k1].push_back(k);
		}
		dfs(0, -1);
		int mx = 0, idx = 0;
		for (int i = 0; i < n; i++)
		{
			if (visited[i] > mx)
				mx = visited[i], idx = i;
		}
		memset(visited, 0, sizeof(visited));
		dfs(idx, -1);
		mx = 0;
		for (int i = 0; i < n; i++)
			if (visited[i] > mx)
				mx = visited[i];
		cout << mx << '\n';
		memset(visited, 0, sizeof(visited));
	}
}
