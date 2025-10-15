/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n,m,k;
    std::cin>>n>>m>>k;
    std::vector<int> q,a(n),b(m);
    for(auto &x:a) std::cin>>x,q.pb(x);
    for(auto &x:b) std::cin>>x,q.pb(x);
    sort(all(q));
    q.erase(unique(all(q)),q.end());
    auto find=[&](int x){
        return lower_bound(all(q),x)-q.begin()+1;
    };

    int len=q.size();
    std::vector<int> cnta(len+10),cntb(len+10);
    for(auto x:a) cnta[find(x)]++;
    for(auto x:b) cntb[find(x)]++;

    int sufa=0,sufb=0;
    for(int i=len;i>=0;i--){
        sufa+=cnta[i],sufb+=cntb[i];
        if(sufa>sufb){
            std::cout<<"YES"<<"\n";
            return;
        }
    }
    std::cout<<"NO"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
