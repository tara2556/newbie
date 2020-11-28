#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
#define mk make_pair
using namespace std;

struct item {
	int m, c;
};

struct SegTree {

	int size;
	vector<item> value;

	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		value.resize(2 * size);
	}

	item merge(item a, item b) {
		if (a.m > b.m) return b;
		if (a.m < b.m) return a;
		return { a.m, a.c + b.c };
	}

	void set(int i, int v, int x, int lx, int rx) {
		while (rx - lx == 1) {
			value[x] = { v, 1 };
			return;
		}
		int mid = (lx + rx) / 2;
		if (i < mid) {
			set(i, v, 2 * x + 1, lx, mid);
		}
		else {
			set(i, v, 2 * x + 2, mid, rx);
		}
		value[x] = merge(value[2 * x + 1], value[2 * x + 2]);
	}

	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	item calc(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return {INT32_MAX, 0};
		if (lx >= l && rx <= r) return value[x];
		int mid = (lx + rx) / 2;
		item s1 = calc(l, r, 2 * x + 1, lx, mid);
		item s2 = calc(l, r, 2 * x + 2, mid, rx);
		return merge(s1, s2);
	}

	item calc(int l, int r) {
		return calc(l, r, 0, 0, size);
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
			item res = st.calc(l, r);
			cout << res.m << ' ' << res.c << '\n';
		}
	}
}
