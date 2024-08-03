/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> cnt(n+2);
    cnt[n]=1;
    for(int i=n,la=0;i>=1;i--){
        cnt[i]+=la;
        for(int l=1,r;l<=i;l=r+1){
            r=i/(i/l);
            int v=i/l;
            if(l!=1) {
                cnt[v]=(cnt[v]+(r-l+1)*cnt[i]%m)%m;
                cnt[v]%=m;
            }
        }
        la=(la+cnt[i])%m;
        la%=m;
    }
    std::cout<<cnt[1]%m<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
