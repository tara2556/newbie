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
vector<int> p;
int prime[100005];
void Sieve()
{
	fill(prime + 2, prime + 100004, 1);
	for (int i = 2; i <= 100005; i++)
	{
		if (prime[i]==1)
		{
			p.push_back(i);
		}
		for (auto j : p)
		{
			if (i*j > 100005) break;
			prime[i*j] = j;
			if (i%j == 0) break;
		}
	}	
}
bool sieve(ll n)
{
	if (n == 1 || n == 0) return 0;
	for (int i = 0;p[i] <= sqrt(n); i++)
		if (!(n%p[i])) return 0;
	return 1;
}
ll ans[10];
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	string a;
	Sieve();
	while (cin >> a)
	{
		int cnt = 0;
		ll t = 0;
		for (int i = 0; i < 10; i++)
		{
			t += a[i] - '0';
			if (sieve(t)) ans[cnt++] = t, t = 0;
			else
				t *= 10;
		}
		cout << cnt << '\n';
		for (int i = 0; i < cnt; i++)
			cout << ans[i] << '\n';
		cout << '\n';
		memset(ans, 0, sizeof(ans));
	}
}
