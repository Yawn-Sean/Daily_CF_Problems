#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
void solve(){
	int n;cin>>n;
    vector<int> cost(n+1);
    vector<int> gap(n+1);
    vector<int> vis(n+1, 0);
    for(int i=1;i<=n;i++)cin>>cost[i];
    for(int i=1;i<=n;i++)cin>>gap[i];
    vector<int> bz=gap;
    for(int k=1;k<=32;k++)
    {
        vector<int> tmp(n+1);
        for(int i=1;i<=n;i++)
        {
            tmp[i]=bz[bz[i]];//倍增思想还是NB啊确实得好好学一学倍增的东西了
        }
        bz=tmp;
    }
    for(auto& it:bz){
        vis[it]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int tmp=i,mini=1e9+7,flag=0;
        
        while(vis[tmp]){
            // cout<<i<<" ";
            vis[tmp]=0;
            mini=min(mini,cost[tmp]);
            tmp=gap[tmp];
            flag=1;
        }
        // cout<<mini<<endl;
        if(flag)ans+=mini;
    }
    cout<<ans<<endl;
}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
