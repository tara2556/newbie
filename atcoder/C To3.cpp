#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string a;
	cin >> a;
	int s = a.size();
	int ans = 20;
	for(int i = 1; i < (1<<s); i++){
		int num = 0;
		int sum = 0;
		for(int j = 0; j < s; j++){
			if(i>>j&1){
				num++,sum+=(a[j]-'0');
			}
		}
		if(sum % 3 ==0){
			ans = min(ans, s-num);
		}
	}
	if(ans==20){
		cout << -1;
	}
	else cout << ans;
}
