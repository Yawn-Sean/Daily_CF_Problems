/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct combine{
    std::vector<int> aa,bb,inv;
    int mx,MOD;
    combine(){}
    combine(int len,int M){
        mx=len,MOD=M;
        aa.clear(),bb.clear(),inv.clear();
        aa.resize(len),bb.resize(len),inv.resize(len);
        inv[1]=1;
        for(int i=2;i<len;i++) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
        aa[0]=1,bb[0]=1;
        for(int i=1;i<len;i++) aa[i]=(1ll*i*aa[i-1])%MOD;
        for(int i=1;i<len;i++) bb[i]=(1ll*inv[i]*bb[i-1])%MOD;
    }
    int C(int x, int y) {
        assert(x<mx and y<mx);
        return x<y or y<0 ? 0: 1ll*aa[x]*bb[y]%MOD*bb[x-y]%MOD;
    }
};

void solve(){
    int n,m;
    std::cin>>n>>m;
    combine cb(n+m+10,1000003);
    std::cout<<cb.C(n+m,m)-1<<"\n";
}

signed main(){
    fastio;

    int T;
    T=1;
    while(T--) solve();

    return 0;
}