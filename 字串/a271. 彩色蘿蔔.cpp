#include <pch.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
bool cmp;
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	int cnt = 0;
	while (t--)
	{
		int x, y, z, w, n, m;
		cin >> x >> y >> z >> w >> n >> m;
		string a;
		cin.ignore();
		getline(cin, a, '\n');
		int d = a.length();
		for (int i = 0; i < d; i += 2)
		{
			if (a[i] <= '9'&&a[i] >= '0')
			{
				if (m <= 0)
					break;
				m -= cnt * n;
				if (m <= 0)				
					break;			
				switch (a[i])
				{
				case '1':
					m += x;
					break;
				case '2':
					m += y;
					break;
				case'3':
					m -= z;
					break;
				case'4':
					m -= w;
					cnt++;
					break;
				}
				if (m <= 0)
					break;
			}
		}		
		if (m <= 0)
			cout << "bye~Rabbit" << '\n';
		else
			cout << m << 'g' << '\n';
		cnt = 0, cmp = 0;
	}
}
