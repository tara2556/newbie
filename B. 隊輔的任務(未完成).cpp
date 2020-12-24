#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
#define mk make_pair
using namespace std;

int visited[500005];
vector<int> p[500005];
vector<int> ans[500005];

void dfs(int i, int s) {
	visited[i] = 1;
	for (int t : p[i]) {
		if (!visited[t]) {
			ans[s].pb(t);
			dfs(t, s);
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		p[k].pb(i);
	}
	int s = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			ans[s].pb(i);
			dfs(i, s);
			if (ans[s].size() == 1) {
				ans[s].clear();
				continue;
			}
			s++;		
		}	
	}
	cout << s << '\n';
	for (int i = 0; i < s; i++) {
		cout << ans[i].size() << ' ';
		for (auto j : ans[i]) {
			cout << j << ' ';
		}
		cout << '\n';
	}
}
