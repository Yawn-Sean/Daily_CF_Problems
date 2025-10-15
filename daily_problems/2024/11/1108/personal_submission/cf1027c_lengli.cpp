/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

using i64=long long;

int cnt[10010];

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x;
    for(auto x:a) cnt[x]++;
    int l=-1,r=-1;
    sort(all(a));

    a.erase(unique(all(a)),a.end());

    auto clear=[&](){
        for(auto x:a) cnt[x]=0;
    };

    for(auto x:a){
        if(cnt[x]>=4) {
            l=x,r=x;
            std::cout<<l<<" "<<l<<" "<<r<<" "<<r<<"\n";
            clear();
            return;
        }
    }
    int u=-1,v=-1;
    for(auto x:a){
        if(cnt[x]>=2) v=x;
        if(u!=-1 and v!=-1){
            if(l==-1) l=u,r=v;
            else{
                if(1ll*(1ll*l*l+1ll*r*r)*u*v>1ll*(1ll*u*u+1ll*v*v)*l*r){
                    l=u,r=v;
                }
            }
        }
        if(cnt[x]>=2) u=x,v=-1;
    }
    

    std::cout<<l<<" "<<l<<" "<<r<<" "<<r<<"\n";
    clear();
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
