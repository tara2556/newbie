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
struct turtle
{
	int s, w;
};
turtle A[5700];
bool cmp(turtle a, turtle b)
{
	return a.s < b.s;
}
int dp[5700];
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int cnt = 0;
	while (cin >> A[cnt].w >> A[cnt].s && !cin.eof()) cnt++;
	sort(A, A + cnt, cmp);
	for (int i = 0; i <= cnt; i++)
		dp[i] = 0xfffffff;
	dp[0] = 0;
	for(int i=0;i<cnt;i++)
		for (int j = cnt; j >= 1; j--)
		{
			if (dp[j - 1] + A[i].w <= A[i].s)
				dp[j] = min(dp[j], dp[j - 1] + A[i].w);
		}
	int ans;
	for (ans = cnt; ans >= 0; ans--)
	{
		if (dp[ans] != 0xfffffff) break;
	}
	cout << ans << '\n';
}
