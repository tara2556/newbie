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
#include <iomanip>
#include <sstream>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
using namespace std;
int dp[22][22];
int ans;
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> dp[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	int t;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int a=0;a<i;a++)
				for (int b = 0; b < j; b++)
				{
					t = dp[i][j] - dp[i][b] + dp[a][b] - dp[a][j];
					if (t > ans) ans = t;
				}
	cout << ans;
}
