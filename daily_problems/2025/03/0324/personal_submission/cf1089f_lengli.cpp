/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long
#define i128 __int128

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> q;
    int val=n;
    for(int i=2;1ll*i*i<=val;i++){
        if(val%i) continue;
        q.pb(i);
        while(val%i==0) val/=i;
    }
    if(val>1) q.pb(val);
    
    if(q.size()==1){
        std::cout<<"NO"<<"\n";
        return;
    }
    std::cout<<"YES"<<"\n";
    std::cout<<2<<"\n";
    int l=q[0],r=q[1];
    Exgcd::init(l,r);
    Exgcd::exgcd(l,r);
    Exgcd::get(n-1);
    i64 rl=Exgcd::x,rr=Exgcd::y;
    int v=std::gcd(rl*l,n),u=std::gcd(rr*r,n);
    std::cout<<rl*l/v<<" "<<n/v<<"\n";
    std::cout<<rr*r/u<<" "<<n/u<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
