#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
#define mk make_pair
using namespace std;
ll bit[200005];
bool cmp = 0;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		ll s, t, p;
		cin >> s >> t >> p;
		bit[s] += p;
		bit[t] -= p;
	}
	for (int i = 0; i < n; i++)
	{
		bit[i + 1] += bit[i];
	}
	for (int i = 0; i < n; i++) if (bit[i] > k) cmp = 1;
	if (cmp) cout << "No";
	else cout << "Yes";
}
