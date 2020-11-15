#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
#define mk make_pair
using namespace std;

int a[9][9], dp[43201];
int cnt = 0;
int it[9], visited[9];

void dfs(int layer, int t) {
	if (layer == t) {
		for (int i = 0; i < t+1; i++) {
			if (!i) dp[cnt] += a[1][it[i]];
			else if (i == t)dp[cnt] += a[it[i-1]][1];
			else dp[cnt] += a[it[i - 1]][it[i]];
		}
		cnt++;
		return;
	}
	for (int i = 2; i <= t+1; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		it[layer] = i;
		dfs(layer + 1, t);
		visited[i] = 0;
	}
}

int po(int t) {
	int res = 1;
	for (int i = t - 1; i >= 1; i--) {
		res *= i;
	}
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t, k;
	cin >> t >> k;
	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= t; j++) {
			cin >> a[i][j];
		}
	}
	dfs(0, t-1);
	int ans = 0;
	for (int i = 0; i < po(t); i++) {
		if (dp[i] == k) ans++;
	}
	cout << ans;
}
