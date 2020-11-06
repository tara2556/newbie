#include <bits/stdc++.h>
#include <unordered_set>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

ll g[5], a[5], b[5];
unordered_set<ll> p;
vector<ll> v;

void deQ() {
	ll s = v.front();
	v.erase(v.begin());
	for (int i = 0; i < 2; i++) {
		b[i] = s & 2047;
		s >>= 11;
	}
}

void enQ() {
	ll s = 0;
	for (int i = 1; i >= 0; i--) {
		if (a[i] < 0 || a[i] > g[i]) return;
		s <<= 11;
		s |= a[i];
	}
	if (p.find(s) != p.end()) return;
	p.insert(s);
	v.push_back(s);
}

int gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	while (n--) {
		mem(a), mem(b), mem(g);
		v.clear(), p.clear();
		bool cmp = 0;
		ll mx = 0;
		for (int i = 0; i < 2; i++) {
			cin >> g[i];
			mx = max(mx, g[i]);
		}
		ll t = g[0];
		for (int i = 1; i < 2; i++) {
			t = gcd(t, g[i]);
		}
		int x;
		cin >> x;
		int ans = 0;
		if (x <= mx && !(x % t)) {
			enQ();
			while (!v.empty()) {
				int sz = v.size();
				ans++;
				while (sz--) {
					deQ();
					for (int i = 0; i < 2; i++) {
						if (b[i] == x) {
							cout << ans - 1 << '\n';
							cmp = 1;
							break;
						}
						a[i] = b[i];
					}
					if (cmp) break;
					for (int i = 0; i < 2; i++) {
						a[i] = g[i];
						enQ();
						a[i] = 0;
						enQ();
						a[i] = b[i];
					}
					for (int i = 0; i < 2; i++) {
						for (int j = 0; j < 2; j++) {
							if (i == j) continue;
							a[i] = max(b[i] + b[j] - g[j], (ll)0);
							a[j] = min(b[i] + b[j], g[j]);
							enQ();
							a[i] = b[i], a[j] = b[j];
						}
					}
				}
				if (cmp) break;
			}
		}
		if (!cmp)
			cout << -1 << '\n';
	}
}
