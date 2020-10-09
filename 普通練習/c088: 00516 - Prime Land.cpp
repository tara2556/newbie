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
#define ll long long
#define pi pair<int,int>
#define mk make_pair
using namespace std;
const int maxn = 32767;
vector<int> p;
int prime[50000];
void sieve()
{
	fill(prime + 2, prime + maxn, 1);
	for (int i = 2; i < maxn; i++)
	{
		if (prime[i] == 1)
			p.push_back(i);
		for (int j : p)
		{
			if (i*j > maxn) break;
			prime[i*j] = j;
			if (!(i%j)) break;
		}
	}
}
int num[100];
int ans[100];
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	sieve();
	string a;
	while (getline(cin, a))
	{
		if (a == "0") break;
		memset(num, 0, sizeof(num));
		memset(ans, 0, sizeof(ans));
		int d = a.length();
		int cnt = 0;
		for (int i = 0; i < d; i++)
		{
			if (isdigit(a[i]))
			{
				num[cnt] *= 10;
				num[cnt] += a[i] - '0';
			}
			else
			{
				cnt++;
			}
		}
		int reg = 1;
		int t = 0;
		for (int i = 0; i <= cnt; i++)
		{
			if (!(i % 2)) t = num[i];
			else reg *= pow(t, num[i]);
		}
		cnt = 0;
		reg--;
		for (int i : p)
		{
			int po = 0;
			if (!(reg%i))
			{
				ans[++cnt] = i;
				po++;
				reg /= i;
				if (reg == 1)
				{
					ans[cnt - 1] = po, cnt++;
					break;
				}
			}
			while (1)
			{
				if (reg%i) break;
				reg /= i;
				po++;
			}
			if (reg == 1)
			{
				ans[cnt - 1] = po, cnt++;
				break;
			}
			else
				if (po)
					ans[cnt - 1] = po, cnt++;
		}
		for (int i = cnt-1; i >= 0; i--)
			cout << ans[i] << ' ';
		cout << '\n';
	}
}
