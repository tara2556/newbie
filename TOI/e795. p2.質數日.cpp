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
int prime[10005];
void Sieve()
{
	fill(prime + 2, prime + 10004, 1);
	for (int i = 2; i <= 10005; i++)
	{
		if (prime[i] == 1)
		{
			p.push_back(i);
		}
		for (auto j : p)
		{
			if (i*j > 10005) break;
			prime[i*j] = j;
			if (i%j == 0) break;
		}
	}
}
bool sieve(ll n)
{
	if (n == 1 || n == 0) return 0;
	for (int i = 0; p[i] <= sqrt(n); i++)
		if (!(n%p[i])) return 0;
	return 1;
}
ll ans[10];
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	Sieve();
	int n;
	cin >> n;
	while (n--)
	{
		string a;
		cin >> a;
		int d = a.length();
		int t = 0;
		bool cmp = 0;
		for (int i = d - 1; i >= 0; i--)
		{
			t +=( a[i] - '0')*(pow(10, d - i - 1));
			if (!sieve(t))
			{
				cmp = 1;
				break;
			}
		}
		if (cmp)
			cout << a << " isn't a Prime Day! " << '\n';
		else
			cout << a << " is a Prime Day! " << '\n';
	}
}
