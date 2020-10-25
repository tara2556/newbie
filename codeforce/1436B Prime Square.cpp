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
int prime[10005];
vector<int> p;
void Prime()
{
	fill(prime + 2, prime + 10001, 1);
	for (int i = 2; i <= 10001; i++)
	{
		if (prime[i] == 1)
		{
			p.push_back(i);
		}
		for (auto j : p)
		{
			if (i*j > 10001) break;
			prime[i*j] = j;
			if (!(i%j)) break;
		}
	}
}
bool jud(int n)
{
	for (auto i : p)
	{
		if (n == i) return 0;
	}
	return 1;
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	Prime();
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		bool cmp = 0;
		for (auto i : p)
			if (n == i)
			{
				cmp = 1;
				break;
			}
		if (cmp)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					cout << 1 << ' ';
				cout << '\n';
			}
		}
		else
		{
			int mi = 1;
			while (1)
			{
				if (jud(mi))
				{					
					if (!(jud(mi + n - 1)))
						break;
				}
				mi++;
			}
			pi cnt = mk(0, 0);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (cnt.fi == i && cnt.se == j)
					{
						cout << mi << ' ';
						cnt.fi++, cnt.se++;
					}
					else
						cout << 1 << ' ';
				}
				cout << '\n';
			}
		}
	}
}
