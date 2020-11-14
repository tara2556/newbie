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
	ll t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				int k;
				cin >> k;
				k += ((k & 1) ^ ((i + j) & 1));
				cout << k << ' ';
			}
		}
	}
}
