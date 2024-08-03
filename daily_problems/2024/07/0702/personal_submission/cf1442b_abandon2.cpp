#include<bits/stdc++.h>
using namespace std;
const int N =2e5+10,md=998244353;
using LL=long long;
int a[N],b[N],pre[N],nxt[N];
int need[N];

void solve(){
    int n,k;       
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=nxt[i]=need[i]=0;
    }
    for(int i=1;i<=n;i++){
        pre[a[i]]=(i>1?a[i-1]:-1);
        nxt[a[i]]=(i<n?a[i+1]:-1);
    }

    for(int i=1;i<=k;i++){
        cin>>b[i];need[b[i]]=1;
    }
    //return;
    LL ans=1;
    for(int i=1;i<=k;i++){
        int q=(pre[b[i]]!=-1&&!need[pre[b[i]]]);
        int h=(nxt[b[i]]!=-1&&!need[nxt[b[i]]]);     
        
        if(q&&h){
            ans*=2LL;
            ans%=md;
        }
        if(!q&&!h){
            ans=0;
            cout<<ans<<"\n";
            return;
        }
        need[b[i]]=0;
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;cin>>tt;while(tt--)
    solve();
    return 0;
}
