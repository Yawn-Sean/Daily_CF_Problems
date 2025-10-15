#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vc vector

signed main()
{
    ios::sync_with_stdio(0), cin.tie(nullptr);
    int n,m,k;cin>>n>>m>>k;
    vc<int>p(n+1);//x位置的软件
    vc<int>mp(n+1);//x号软件的位置
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        p[i]=x;
        mp[x]=i;
    }
    int ans=0;
    while(m--){
        int x;cin>>x;
        int t=mp[x];
        ans+=(t+k-1)/k;
        if(t>1){
            int y=p[t-1];
            swap(p[t-1],p[t]);
            swap(mp[y],mp[x]);
        }
    }
    cout<<ans<<endl;
}   
