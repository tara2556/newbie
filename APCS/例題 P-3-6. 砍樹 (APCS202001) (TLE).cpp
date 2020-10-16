#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Point
{
    int x;
    int y;
};
Point po[100005];
int cut[100005];
int ans,pre,n,l;
set<int> tree;
void cut_tree(int i)
{
    if(po[i].x-po[i].y>=0||po[i].y+po[i].x<=l)
    {
        int L=i-1;
        while(L>0&&cut[L]==1) L--;
        int R=i+1;
        while(R<n-1&&cut[R]==1) R++;
        if((i>0&&po[i].x-po[i].y>=po[L].x)||(i<n-1&&po[i].x+po[i].y<=po[R].x))
        {
            ans++;
            tree.insert(po[i].y);
            cut[i]=1;
        }
    }

}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>l;
    for(int i=0; i<n; i++)
        cin>>po[i].x;
    for(int i=0; i<n; i++)
        cin>>po[i].y;
    bool flag=1;
    ans=0,pre=0;
    while(flag)
    {
        for(int i=0; i<n; i++)
            if(cut[i]==0)
                cut_tree(i);
        flag=(ans!=pre);
        pre=ans;
    }
    cout<<ans<<'\n';
    if(tree.size()) cout<< *(--tree.end())<<'\n' ;
    else cout<<"0\n";

}
