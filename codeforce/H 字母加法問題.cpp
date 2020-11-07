#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string a, b;
	cin >> a >> b;
	ll s1 = 0, s2 = 0;
	int d1 = a.length(), d2 = b.length();
	for (int i = 0; i < d1; i++) {
		s1 *= 10;
		if (isalpha(a[i])) {
			if (a[i] - 'A' + 1 >= 10) s1 *= 10;
			s1 += a[i] - 'A' + 1;
		}
		else s1 += a[i] - '0';
	}
	for (int i = 0; i < d2; i++) {
		s2 *= 10;
		if (isalpha(b[i])) {
			if (b[i] - 'A' + 1 >= 10) s2 *= 10;
			s2 += b[i] - 'A' + 1;
		}
		else s2 += b[i] - '0';
	}
	cout << (ll)s1 + s2;
}
