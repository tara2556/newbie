#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#define ll long long
using namespace std;
map<ll, int> mp;
ll mask, cnt;
int jud[38], ans;
int iter(char n)
{
	if (n <= 'Z')
		return n - 'A';
	else
		return n - 'a' + 26;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		mask |= (1LL << i);
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		memset(jud, 0, sizeof(jud));
		cnt = 0;
		int d = a.length();
		for (int j = 0; j < d; j++)
		{
			jud[iter(a[j])] = 1;
		}
		for (int j = 0; j < m; j++)
		{
			if (jud[j]) cnt |= (1LL << j);
		}
		if (mp.count(cnt^mask)) ans += mp[cnt^mask];
		if (mp.count(cnt)) mp[cnt]++;
		else
			mp[cnt] = 1;
	}
	cout << ans;
}
