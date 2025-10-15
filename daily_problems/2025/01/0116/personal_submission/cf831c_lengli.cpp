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
    int n,k;
    std::cin>>n>>k;
    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x;

    std::set<int> s;
    s.insert(a[0]);
    for(int i=1;i<n;i++){
        a[i]+=a[i-1];
        s.insert(a[i]);
    }

    std::set<int> res;
    std::vector<int> b(k);
    for(auto &x:b) std::cin>>x;
    for(int i=0;i<n;i++){
        int v=b[0]-a[i];
        bool flag=1;
        for(int j=1;j<k and flag;j++){
            if(!s.count(b[j]-v)) flag=0;
        }
        if(flag) res.insert(v);
    }
    std::cout<<res.size()<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
