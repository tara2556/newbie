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
int poker[20];
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n, m;
	int b = 1;
	while (cin >> n >> m)
	{
		cout << "Selection #" << b++ << '\n';
		vector<int> s(n);
		for (int i = 1; i <= n; i++)
			s[i - 1] = i;
		for (int i = 0; i <20; i++)
			cin >> poker[i];
		int sr = n;
		int st = 20;
		if (n == m)
		{
			for (int i = 1; i <= n; i++)
				cout << s[i - 1] << ' ';
			cout << "\n\n";

		}
		else
		{ 		
			int cnt = 0, i = 0, t = 0;
			while (st)
			{
				t += poker[i] - 1;
				while (t >= s.size())
				{
					st--;
					if (!st) break;
					t = poker[++i] - 1;
				}
				if (!st) break;
				s.erase(s.begin() + t);
				sr--;
				if (sr == m) break;
			}
			for (int i = 0; i < s.size(); i++)
				if (s[i])
					cout << s[i] << ' ';
			cout << "\n\n";
		}
	}
}
