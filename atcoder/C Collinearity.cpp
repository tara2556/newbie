#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

struct Point{
    int x, y;
};
Point s[102];
map<int,int> mpx;
map<int,int> mpy;
int main(){
    int n;
    cin >> n;
    bool cmp = 0;
    for(int i = 0; i < n; i++){
        cin >> s[i].x >> s[i].y;
        mpx[s[i].x]++;
        mpy[s[i].y]++;
        if(mpx[s[i].x]==3||mpy[s[i].y]==3){           
            cmp = 1;
        }
    }
    if(cmp) {
        cout << "Yes";
        return 0;
    }
    map<double,int> ma;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(i!=j && j!=k){
                    double t1 = (double)abs(s[j].y-s[i].y)/(double)abs(s[j].x-s[i].x);
                    double t2 = (double)abs(s[j].y-s[k].y)/(double)abs(s[j].x-s[k].x);
                    double t3 = (double)abs(s[k].y-s[i].y)/(double)abs(s[k].x-s[i].x);                   
                    if(t1==t2 && t2==t3){                       
                        cout << "Yes";
                        return 0;                                            
                    }
                }
            }
            
        }
    }
    cout << "No";
}
