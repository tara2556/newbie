#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define mem(a) memset((a),0,sizeof(a))
using namespace std;
vector<int> p;
void sieve(int n){
    for(int i = 2; i*i <= n; i++){
        if(!(n % i)){
            p.push_back(i);
            while(!(n % i)) n /= i;
        }
    }
    if(n != 1) p.push_back(n);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);	
    int t;
    cin >> t;
    while(t--){
        ll n, q;
        cin >> n >> q;
        p.clear();
        sieve(q);
        ll mx = 0;
        for(int i : p) {
            ll h = n;
            while(!(h % q)) h /= i;
            mx = max(mx, h);
        }
        cout << mx << '\n';
    }
}
