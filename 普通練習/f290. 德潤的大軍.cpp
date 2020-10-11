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
int num[1000005];
int def[1000005], at[1000005];
bool cmp(int a, int b)
{
	if (at[a] == at[b])
		return def[a] < def[b];
	else
		return at[a] < at[b];
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> def[i];
		num[i] = i;
	}
	at[0] = def[0], at[n - 1] = def[n - 1];
	for (int i = 1; i < n - 1; i++)
	{
		at[i] = def[i - 1] + def[i + 1];
	}
	sort(num, num + n, cmp);
	for (int i = 0; i < n; i++)
	{
		cout << at[num[i]] << ' ' << def[num[i]];
		cout << '\n';
	}
}
