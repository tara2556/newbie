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
	string s;
	cin >> s;
	s += '$';
	int d = s.length();
	vector<int> p(d), c(d);
	{
		vector<pair<char, int>> a(d);
		for (int i = 0; i < d; i++) {
			a[i] = { s[i], i };
		}
		sort(a.begin(), a.end());

		for (int i = 0; i < d; i++) p[i] = a[i].se;
		c[p[0]] = 0;
		for (int i = 1; i < d; i++) {
			if (a[i].fi == a[i - 1].fi) {
				c[p[i]] = c[p[i - 1]];
			}
			else {
				c[p[i]] = c[p[i - 1]] + 1;
			}
		}
	}

	int k = 0;
	while ((1 << k) < d) {
		vector<pair<pi,int>> a(d);
		for (int i = 0; i < d; i++) {
			a[i] = { {c[i], c[(i+(1 << k)) % d]} , i };
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < d; i++) p[i] = a[i].se;
		c[p[0]] = 0;
		for (int i = 1; i < d; i++) {
			if (a[i].fi == a[i - 1].fi) {
				c[p[i]] = c[p[i - 1]];
			}
			else {
				c[p[i]] = c[p[i - 1]] + 1;
			}
		}
		k++;
	}

	for (int i = 0; i < d; i++) {
		cout << p[i] << '\n';
	}
}
