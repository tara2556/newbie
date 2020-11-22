#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
#define mk make_pair
using namespace std;

vector<int> v[25];
int visited[25];
int tr[25];
int a[25];
bool cmp;
void dfs(int n, int x, int tar) {
	visited[n] = 1;
	if (n == tar) {
		if (tr[n]) {
			tr[n] = min(tr[n], x);
		}
		else
		tr[n] = x;
		visited[n] = 0;
	}
	if (v[n].empty()) {
		cmp = 1;
		return;
	}
	for (int i : v[n]) {
		if (!visited[i]) {
			dfs(i, x + 1, tar);
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, q, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int k1, k2;
		cin >> k1 >> k2;
		v[k1].pb(k2);
		v[k2].pb(k1);
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			cout << 1 << ' ';
			cmp = 1;
			break;
		}
	}
	if (cmp) return 0;
	for (int i = 0; i < q; i++) {
		dfs(1, 0, a[i]);
		if (cmp) break;
		mem(visited);
	}
	if (cmp) return 0;
	int mx = 1e9;
	for (int i = 0; i < q; i++) {
		if(tr[a[i]])
		mx = min(mx, tr[a[i]]);
	}
	sort(a, a + q);
	for (int i = 0; i < q; i++) {	
		if (tr[a[i]] == mx && tr[a[i]]) cout << a[i] << ' ';
	}
}
