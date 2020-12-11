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
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		int dis = 0;
		int ans = 1;
		for (int i = 2; i <= sqrt(n); i++) {
			ll cnt = n, now = 0;
			while (cnt % i == 0) {
				cnt /= i;
				now++;
			}
			if (now > ans) {
				ans = now;
				dis = i;
			}
		}
		cout << ans << '\n';
		for (int i = 1; i < ans; i++) cout << dis << ' ', n /= dis;
		cout << n << '\n';
	}
}
