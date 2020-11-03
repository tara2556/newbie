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
	int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        string res;
        cin.ignore();
        getline(cin, res);
        int d = res.length();
        bool bomb = 0;
        int dig = 1e5;
        bool cmp = 0; 
        ll ans = 0;      
        for(int i = 0; i < d; i++){
            if(res[i] == '1'){
                bomb = 1;
                ans += min(a,b*dig);
                dig = 0;
            }
            else if(bomb) dig++;
        }             
       cout << ans <<'\n';
    }
}
