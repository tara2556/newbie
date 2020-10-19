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
#include <sstream>
#include <stack>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
#define fi first
#define se second
using namespace std;
int arr[52][10002];
int dp[52][10002][2];
set<int> p;
const int N = -20000000;
void init(int m,int n)
{
	for (int i = 1; i <= m; i++)
		for (int j = 0; j <= n; j++)
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = N;
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int m, n;
	cin >> m >> n;
	init(m, n);
	for (int i = 1; i <= m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (!i && !j) dp[i][j][0] = arr[i][j];
			if (!i&&j == n - 1) dp[i][j][1] = arr[i][j];
		}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < n; j++)
		{
				dp[i][j][0] = arr[i][j] + max(dp[i][j - 1][0], dp[i - 1][j][0]);
		}
		for (int j = n - 1; j >= 0; j--)
		{
				dp[i][j][1] = arr[i][j] + max(dp[i - 1][j][0], dp[i][j + 1][1]);
		}
		for (int j = 0; j < n; j++)
			dp[i][j][0] = max(dp[i][j][1], dp[i][j][0]);
	}
	for (int i = 0; i < n; i++)
		p.insert(dp[m][i][0]);
	cout << *(--p.end());
}
