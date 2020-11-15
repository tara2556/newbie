#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
#define mk make_pair
using namespace std;

int a[10][10];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		ll ans = 0;
		int mx = 1e9;
		int minus = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				ans += abs(a[i][j]);
				if (a[i][j] < 0) minus++;
					mx = min(mx, abs(a[i][j]));
			}
		}
		if (minus & 1)
			cout << ans - (2 * mx) << '\n';
		else cout << ans << '\n';
		for (int i = 0; i < 10; i++) mem(a[i]);
	}
}
