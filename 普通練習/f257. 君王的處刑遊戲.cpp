#include <pch.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define pi pair
#define mk make_pair
using namespace std;
int simulation[102][102];
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < 102; i++)
			memset(simulation, 0, sizeof(simulation));
		int u, v;
		int k;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> u >> v;
			if (simulation[u][v] == -1) continue;
			simulation[u][v] = -1;
			for (int j = u - 1; j <= u + 1; j++)
			{
				for (int k = v - 1; k <= v + 1; k++)
				{
					if (j >= 0 && j < n&&k >= 0 && k < n&&simulation[j][k] != -1)
						simulation[j][k]++;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (simulation[j][i] == -1)
					cout << "x";
				else
					cout << simulation[j][i];
			}
			cout << '\n';
		}		
	}
}
