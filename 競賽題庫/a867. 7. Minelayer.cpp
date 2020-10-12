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
char a[15][30];
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (cin >> a[0][0])
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				if (!i && !j) continue;
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				if (a[i][j] == '.')
				{
					int cnt = 0;
					if (i != 0 && j != 0 && i != 15 - 1 && j != 30 - 1)
					{
						for (int s = i - 1; s <= i + 1; s++)
							for (int t = j - 1; t <= j + 1; t++)
							{
								if (a[s][t] == '*') cnt++;
							}
						if (cnt)
							a[i][j] = cnt + '0';
						cout << a[i][j];
					}
					else if (i == 0 & j == 0)
					{
						for (int s = i; s <= i + 1; s++)
							for (int t = j; t <= j + 1; t++)
							{
								if (a[s][t] == '*') cnt++;
							}
						if (cnt)
							a[i][j] = cnt + '0';
						cout << a[i][j];
					}
					else if (i == 0 && j != 0 && j != 30 - 1)
					{
						for (int s = i; s <= i + 1; s++)
							for (int t = j - 1; t <= j + 1; t++)
							{
								if (a[s][t] == '*') cnt++;
							}
						if (cnt)
							a[i][j] = cnt + '0';
						cout << a[i][j];
					}
					else if (j == 0 && i != 0 && i != 15 - 1)
					{
						for (int s = i - 1; s <= i + 1; s++)
							for (int t = j; t <= j + 1; t++)
							{
								if (a[s][t] == '*') cnt++;
							}
						if (cnt)
							a[i][j] = cnt + '0';
						cout << a[i][j];
					}
					else if (j == 29 && i == 14)
					{
						for (int s = i - 1; s <= i; s++)
							for (int t = j - 1; t <= j; t++)
							{
								if (a[s][t] == '*') cnt++;
							}
						if (cnt)
							a[i][j] = cnt + '0';
						cout << a[i][j];
					}
					else if (j == 29 && i > 0 && i != 14)
					{
						for (int s = i - 1; s <= i + 1; s++)
							for (int t = j - 1; t <= j; t++)
							{
								if (a[s][t] == '*') cnt++;
							}
						if (cnt)
							a[i][j] = cnt + '0';
						cout << a[i][j];
					}
					else if (i == 14 && j > 0 && j != 29)
					{
						for (int s = i - 1; s <= i; s++)
							for (int t = j - 1; t <= j + 1; t++)
							{
								if (a[s][t] == '*') cnt++;
							}
						if (cnt)
							a[i][j] = cnt + '0';
						cout << a[i][j];
					}
					else if (i == 14 && j == 0)
					{
						for (int s = i - 1; s <= i; s++)
							for (int t = j; t <= j + 1; t++)
							{
								if (a[s][t] == '*') cnt++;
							}
						if (cnt)
							a[i][j] = cnt + '0';
						cout << a[i][j];
					}
					else if (i == 0 && j == 29)
					{
						for (int s = i; s <= i + 1; s++)
							for (int t = j - 1; t <= j; t++)
							{
								if (a[s][t] == '*') cnt++;
							}
						if (cnt)
							a[i][j] = cnt + '0';
						cout << a[i][j];
					}
				}
				else
					cout << a[i][j];
			}
			cout << '\n';
		}
	}
}
