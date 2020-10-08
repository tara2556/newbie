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
int num[1020];
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	string n;
	while (cin >> n)
	{
		string b, c;
		b = n, c = b;
		int d = n.length();
		ll ans = 0;
		for (int i = 0; i < d; i++)
			ans *= 10, ans += n[i] - '0';
		ll br = 0, cr = 0;
		for (int i = 0; i <= d; i++)
		{
			if (!((n[i] - '0') % 2))
			{
				b[i] += 1;
				for (int j = i + 1; j < d; j++)
					b[j] = '1';
				c[i] -= 1;
				if (c[i] < '0')
				{
					int cnt = 1;
					while (1)
					{
						if (i - cnt == 0)
						{
							c[i - cnt] = '0';
							for (int j = 1; j < d; j++)
								c[j] = '9';
							break;
						}
						c[i - cnt] -= 2;						
						for (int j = i - cnt + 1; j < d; j++)
							c[j] = '9';				
						if (c[i - cnt] >= '0') break;
						cnt++;
					}
				}
				else
					for (int j = i + 1; j < d; j++)
						c[j] = '9';
				break;
			}
		}
		for (int i = 0; i < b.length(); i++)
			br *= 10, br += b[i] - '0';
		for (int i = 0; i < c.length(); i++)
			cr *= 10, cr += c[i] - '0';
		cout << min(abs(br - ans), abs(cr - ans)) << '\n';
	}
}
