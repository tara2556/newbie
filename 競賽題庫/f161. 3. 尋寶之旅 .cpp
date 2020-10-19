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
vector<int> p[200005];
int col[200005];
map<int,int> coun;
int mx = 0;
void dfs(int n)
{
	coun[col[n]]++;
	mx = max(coun[col[n]], mx);
	for (auto i : p[n])
	{
		dfs(i);
	}
	coun[col[n]]--;
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> col[i];
	for (int i = 0; i < n - 1; i++)
	{
		int k1,k2;
		cin >> k1 >> k2;
		p[k1].push_back(k2);
	}
	dfs(0);	
	cout << mx;
}
