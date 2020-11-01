#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

int num1[100], num2[100], num3[100];
string plu(string a, string b){
    int d = a.length();
    int e = b.length();
    for(int i = d-1, j = 0; i >= 0; i--){
        num1[j++] = a[i]-'0'; 
    }
    for(int i = e-1, j = 0; i >= 0; i--){
        num2[j++] = b[i]-'0';
    }
    for(int i = 0; i < max(d,e); i++){
        num3[i] = num1[i]+num2[i];
    }    
    string res;
    for(int i = 0; i < max(d,e)+1; i++){
        if(num3[i]/10){
            num3[i+1] += num3[i]/10;
            num3[i] %= 10;
        }
        res += num3[i]+'0';
    }
    reverse(res.begin(),res.end());
    if(res[0]=='0') res.erase(0,1);  
    mem(num1), mem(num2), mem(num3);
    return res;
}
string cros(string a, string b){
    int d = a.length();
    int e = b.length();
    for(int i = d-1, j = 0; i >= 0; i--){
        num1[j++] = a[i]-'0'; 
    }
    for(int i = e-1, j = 0; i >= 0; i--){
        num2[j++] = b[i]-'0';
    }
    for(int i = 0; i < d; i++){
      for(int j = 0; j < e; j++)
        num3[j+i] += num1[i]*num2[j];
    }    
    string res;
    for(int i = 0; i < d+e; i++){
        if(num3[i]/10){
            num3[i+1] += num3[i]/10;
            num3[i] %= 10;
        }
        res += num3[i]+'0';
    }   
    reverse(res.begin(),res.end());
    if(res[0]=='0') res.erase(0,1);
    mem(num1), mem(num2), mem(num3);
    return res;
}
string ss(ll n){
    int cnt = 0;
    int t = n;
    while(t){
        cnt++;
        t/=10;
    }
    string res;
    for(int i = 0; i < cnt; i++){
        res+=(n%10)+'0';
        n/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}
int main(){
    int n;
    cin >> n;
    string ans = "0";
    for(int i = 0; i < n; i++){
        int k1 ,k2;
        cin >> k1 >> k2;
        int w = k2-k1+1;
        int x = k1+k2;
        if(w%2) x/=2;
        else w/=2;
        string t = cros(ss(x),ss(w));
        ans = plu(ans,t);
    }
    cout << ans;
}
