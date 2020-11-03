#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

int Sequence[100005];
bool cmp(int a, int b){
    return a > b;
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string a, b;
    mem(Sequence);
    cin >> a >> b;
    int n;
    cin >> n;
    char l = a[0], r = a[a.length()-1];
    int d = b.length();
    vector<int> place;
    for(int i = 0; i < d; i++){
        if(b[i] == l) place.push_back(i);
    }
    int cnt = 0;
    for(auto i : place){
        for(int j = i; j < d; j++){
            if(b[j] == r){
                string check = a;               
                for(int k = i; k <= j; k++){                    
                        if(b[k]==check[0]) check.erase(0,1);
                }
                if(check == "")
                    Sequence[cnt++] = j - i;
            }             
        }
    }
    if(cnt == 0){
        cout << 0 <<'\n';
        return 0;
    }
    sort(Sequence, Sequence + cnt, cmp);
    ll ans = 0;
    for(int i = 0; i < min(cnt, n); i++){
        ans +=Sequence[i] + 1;
    }
    cout << ans;
}
