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
    std::vector<int> a(n),p(n+1);
    for(int i=0;i<n;i++){
        std::cin>>a[i];
        p[a[i]]=i;
    }
    std::vector<int> b(m);
    for(int i=0;i<m;i++){
        std::cin>>b[i];
    }

    i64 res=0;
    for(auto i:b){
        int pos=p[i],pre=pos-1;
        res+=pos/k+1;
        if(pre!=-1){
            std::swap(a[pos],a[pre]);
            p[a[pre]]=pre;
            p[a[pos]]=pos;
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
