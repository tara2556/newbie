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
#include <cstdlib>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
using namespace std;
int num[13];
int arrangement[6];
int top;
int n;
void dfs(int d, int k)
{
	if (k == 6)
	{
		for (int i = 0; i < 5; i++)
			cout << arrangement[i] << ' ';
		cout << arrangement[5] << '\n';
		return;
	}
	for (int i = d; i < n; i++)
	{
		arrangement[k] = num[i];
		dfs(i + 1, k + 1);
	}
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int t = 0;
	while (cin >> n && n)
	{
		if (t) cout << '\n';
		t++;
		for (int i = 0; i < n; i++)
			cin >> num[i];
		dfs(0, 0);
		memset(num, 0, sizeof(num));
		top = -1;
	}
}
