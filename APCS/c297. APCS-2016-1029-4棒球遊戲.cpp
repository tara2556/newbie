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
string str[100][9];
int dp[4];
int score;
int out;
int cmp[4];
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n, t = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> n;
		t = max(t, n);
		for (int j = 0; j < n; j++)
			cin >> str[j][i];
	}
	int a;
	cin >> a;
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (str[i][j] == "1B")
			{
				for (int k = 0; k < 4; k++)
				{
					if ((dp[k] && !cmp[k]) || (dp[k] > 1 && cmp[k]))
					{
						dp[k]--;
						if (k + 1 >= 3)
						{
							score++;
							if (!k) dp[k]++;
							continue;
						}
						dp[k + 1]++, cmp[k + 1] = 1;
					}
					if (!k) dp[k]++;
				}
				memset(cmp, 0, sizeof(cmp));
			}
			else if (str[i][j] == "2B")
			{
				for (int k = 0; k < 4; k++)
				{
					if ((dp[k] && !cmp[k]) || (dp[k] > 1 && cmp[k]))
					{
						dp[k]--;
						if (k + 2 >= 3)
						{
							score++;
							if (k == 1) dp[k]++;
							continue;
						}
						dp[k + 2]++, cmp[k + 2] = 1;
					}
					if (k == 1) dp[k]++;
				}
				memset(cmp, 0, sizeof(cmp));
			}
			else if (str[i][j] == "3B")
			{
				for (int k = 0; k < 4; k++)
				{
					if ((dp[k] && !cmp[k]) || (dp[k] > 1 && cmp[k]))
					{
						dp[k]--;
						if (k + 3 >= 3)
						{
							score++;
							if (k == 2) dp[k]++;
							continue;
						}
						dp[k + 3]++, cmp[k + 3] = 1;
					}
					if (k == 2) dp[k]++;
				}
				memset(cmp, 0, sizeof(cmp));
			}
			else if (str[i][j] == "HR")
			{
				for (int k = 0; k < 4; k++)
				{
					if (k == 3) score++;
					if (dp[k])
					{
						dp[k] = 0;
						score++;
					}
				}
			}
			else if (str[i][j] == "SO" || str[i][j] == "FO" || str[i][j] == "GO")
			{
				out++;
				if (!(out%3))
					memset(dp, 0, sizeof(dp));
				if (out == a)
				{
					cout << score;
					break;
				}
			}
		}
	}
}
