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
    i64 n,k;
    std::cin>>n>>k;
    std::vector<int> a(n);
    std::map<int,int> q;
    for(auto &x:a) std::cin>>x,q[x]++;
    std::sort(all(a));
    int l=a[(k-1)/n],r=-1;
    a.erase(std::unique(all(a)),a.end());
    auto it=std::lower_bound(all(a),l)-a.begin();
    for(int i=0;i<it;i++){
        k-=1ll*q[a[i]]*n;
    }
    for(auto x:a){
        i64 t=1ll*q[x]*q[l];
        if(t>=k){
            r=x;
            break;
        }
        k-=t;
    }
    std::cout<<l<<" "<<r<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
