#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
#define mk make_pair
using namespace std;

void count_sort(vector<int> &p, vector<int> &c) {
	int s = p.size();
	vector<int> cnt(s);
	for (auto i : c) {
		cnt[i]++;
	}
	vector<int> p_new(s);
	vector<int> pos(s);
	pos[0] = 0;
	for (int i = 1; i < s; i++) {
		pos[i] = pos[i - 1] + cnt[i - 1];
	}
	for (auto i : p) {
		int x = c[i];
		p_new[pos[x]] = i;
		pos[x]++;
	}
	p = p_new;


}

void suffix_array(string s, vector<int> &p, vector<int> &c) {
	int d = s.size();
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
		for (int i = 0; i < d; i++) {
			p[i] = (p[i] - (1 << k) + d) % d;
		}
		count_sort(p, c);
		vector<int> c_new(d);
		c_new[p[0]] = 0;
		for (int i = 1; i < d; i++) {
			pi prev = { c[p[i - 1]], c[(p[i - 1] + (1 << k)) % d] };
			pi now = { c[p[i]], c[(p[i] + (1 << k)) % d] };
			if (prev == now) {
				c_new[p[i]] = c_new[p[i - 1]];
			}
			else {
				c_new[p[i]] = c_new[p[i - 1]] + 1;
			}
		}
		c = c_new;
		k++;
	}

}

bool bsearch(vector<int> &p, string s, string idx) {
	int l = 0, r = p.size();
	int d = s.size();
	while (l < r) {
		int mid = (l + r) >> 1;
		string res = idx.substr(p[mid], d);
		if (s < res) r = mid;
		else if (s > res) l = mid + 1;
		else return 1;
	}
	return 0;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	s += '$';
	int d = s.length();
	vector<int> p(d), c(d);
	suffix_array(s, p, c);
	int t;
	cin >> t;
	while (t--) {
		string res;
		cin >> res;
		if (bsearch(p, res, s)) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
}
