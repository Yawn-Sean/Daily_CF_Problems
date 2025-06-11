/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=200010;

int n;
int a[N],pre[N];

void solve(){
    std::cin>>n;
    for(int i=1;i<=n;i++) std::cin>>a[i];
    int mx=-1,idx=-1;
    for(int i=1;i<=n;i++){
        if(mx<=a[i]){
            mx=a[i];
            idx=i;
        }
    }

    i64 res=0;
    int cnt=mx+1;

    for(int i=idx+1;i<=n;i++) res+=cnt-(a[i]+1);

    pre[0]=-1;
    for(int i=1;i<=n;i++) pre[i]=std::max(pre[i-1],a[i]);

    for(int i=idx;i>=1;i--){
        res+=cnt-(a[i]+1);
        if(cnt-1>=pre[i-1]+1){
            cnt--;
        }
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
