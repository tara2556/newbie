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
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	while (cin >> n && n)
	{
		bool cmp = 0;
		for (int b = 1234; b <= 98765/n; b++)
		{
			int a = b * n;
			int c = a, d = b;
			int count = (d < 10000);
			while (d)
			{
				count |= (1 << (d % 10));
				d /= 10;
			}
			while (c)
			{
				count |= (1 << (c % 10));
				c /= 10;
			}
			if (count == (1 << 10) - 1)
			{
				cout << a << " / ";
				if (b < 10000) cout << 0;
				cout << b << " = " << n << '\n';
				cmp = 1;
			}
		}
		if (!cmp) cout << "There are no solutions for " << n << '.';
		cout << '\n';
	}
}
