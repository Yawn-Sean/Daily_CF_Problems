/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::string a,b;
    std::cin>>n>>a>>b;
    int p1=0,p0=0,q1=0,q0=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]) {
            if(a[i]=='0') p0++;
            else p1++;
        }else if(a[i]=='0') q0++;
        else q1++;
    }

    if(p0+p1==n) {
        std::cout<<0<<"\n";
        return;
    }

    int res=1e9;

    if(p0==p1-1){
        int ans=0;
        ans+=p0*2;
        ans++;
        res=std::min(res,ans);
    }
    if(q0==q1){
        int ans=0;
        ans+=q0*2;
        res=std::min(res,ans);
    }
    if(res==1e9) res=-1;
    std::cout<<res<<"\n";

}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
