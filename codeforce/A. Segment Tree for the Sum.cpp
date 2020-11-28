#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
#define mk make_pair
using namespace std;

struct SegTree {

	int size;
	vector<ll> sums;

	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		sums.assign(2 * size, 0);
	}

	void set(int i, int v, int x, int lx, int rx) {
		while (rx - lx == 1) {
			sums[x] = v;
			return;
		}
		int mid = (lx + rx) / 2;
		if (i < mid) {
			set(i, v, 2 * x + 1, lx, mid);
		}
		else {
			set(i, v, 2 * x + 2, mid, rx);
		}
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}

	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	ll sum(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return 0;
		if (lx >= l && rx <= r) return sums[x];
		int mid = (lx + rx) / 2;
		ll s1 = sum(l, r, 2 * x + 1, lx, mid);
		ll s2 = sum(l, r, 2 * x + 2, mid, rx);
		return s1 + s2;
	}

	ll sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}

};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	SegTree st;
	int n, m;
	cin >> n >> m;
	st.init(n);
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		st.set(i, v);
	}
	for (int i = 0; i < m; i++) {
		int op;
		cin >> op;
		if (op == 1) {
			int i, v;
			cin >> i >> v;
			st.set(i, v);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << st.sum(l, r) << '\n';
		}
	}
}
