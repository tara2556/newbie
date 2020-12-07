#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
#define mk make_pair
using namespace std;

int num[502], b[502];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
			b[i] = num[i];
		}
		sort(b, b + n);
		bool cmp = 0;
		for (int i = 0; i < n; i++) {
			if (num[i] != b[i]) cmp = 1;
		}
		if (!cmp) {
			cout << 0 << '\n';
			continue;
		}
		int pos;
		for (int i = n - 1; i >= 1; i--) {
			if (num[i] < num[i - 1]) {
				pos = i - 1;
				break;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (i <= pos) {
				if (num[i] > x) {
					swap(num[i], x);
					ans++;
				}
			}
			else {
				if (num[i] > num[i + 1] && i < n - 1) {
					swap(num[i], x);
					ans++;
				}
			}
			b[i] = num[i];
		}
		sort(b, b + n);
		for (int i = 0; i < n; i++) {
			if (b[i] != num[i]) {
				cmp = 0;
				break;
			}
		}
		if (!cmp) cout << -1 << '\n';
		else cout << ans << '\n';
	}
}
