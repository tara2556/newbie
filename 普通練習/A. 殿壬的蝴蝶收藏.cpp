#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
#define mk make_pair
using namespace std;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	map<int, int> p;
	map<int, int> ans;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		p[k]++;
	}
	while (m--) {
		int t, s;
		cin >> t >> s;
		if (t) {
			ans[s]++;
		}
		else {
			ans[s]--;
			if (ans[s] < 0) {
				ans[s] = 0;
				p[s]--;
			}
		}
	}
	int r = 0;
	vector<int> w;
	for (auto i : p) {
		if (i.se > 0) {
			r += i.se;
			w.pb(i.fi);
		}
	}
	cout << r << '\n';
	for (auto i : w) {
		for (int j = 0; j < p[i]; j++)
			cout << i << ' ';
	}
}
