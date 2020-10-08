#include <pch.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <vector>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
using namespace std;
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	double u, f, h, d;
	while (cin >> h >> u >> d >> f && h)
	{
		int t = u;
		f /= 100;
		int day = 0;
		double height = 0;
		while (1)
		{
			day++;
			height += u;
			if (height > h)
			{
				cout << "success on day " << day << '\n';
				break;
			}
			height -= d;
			if (height < 0)
			{
				cout << "failure on day " << day << '\n';
				break;
			}
			u -= t * f;
			if (u < 0) u = 0;
		}
	}
}
