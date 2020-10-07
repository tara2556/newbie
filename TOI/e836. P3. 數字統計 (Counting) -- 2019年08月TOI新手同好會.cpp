#include <pch.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
using namespace std;
set<int> p;
int num[200005];
map<int, int> cmp1;
map<int, int> r;
int cmp;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		p.insert(k);
		r[k] += 1;
		num[i] = k;
	}
	cout << p.size() << '\n';
	int maxn = 0;
	for (auto i : r)
	{
		maxn = max(maxn, i.second);
	}
	for (int i = 0; i < n; i++)
	{
		if (r[num[i]] == maxn&&!cmp1[num[i]])
			if (r[num[i]] > 1)
				cout << num[i] << ' ', cmp = 1, cmp1[num[i]] = 1;
	}
	if (!cmp) cout << "NO";
}
