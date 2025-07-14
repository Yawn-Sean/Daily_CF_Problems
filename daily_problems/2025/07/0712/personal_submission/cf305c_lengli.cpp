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
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x;
    std::set<int> s;

    int mx=0;

    for(auto x:a){
        while(s.count(x)){
            s.erase(x);
            x++;   
        }
        s.insert(x);
        mx=std::max(mx,x);
    }

    std::cout<<mx-(int)s.size()+1<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
