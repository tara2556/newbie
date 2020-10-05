#include <pch.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#define ll long long
#define pi pair
#define mk make_pair
using namespace std;
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	while (cin >> n)
	{
		int ans = 0;
		map<int, pi<int, int>> p;
		for (int i = 0; i < n; i++)
		{
			int k1, k2;
			cin >> k1 >> k2;
			p[i] = mk(k1, k2);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (p[i].first == p[j].second&&p[i].second == p[j].first&&p[i].first!=-1)
				{
					p[i] = mk(-1, -1) ,p[j] = mk(-1, -1);
					ans++;
				}
			}
		cout << ans << '\n';
	}
}
