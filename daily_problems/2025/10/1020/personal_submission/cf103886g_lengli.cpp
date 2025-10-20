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

    std::vector<int> s={0};
    while((int)s.size()<n){
        std::vector<int> t;
        t.reserve(std::min(n,(int)s.size()*2));
        for(int x:s){
            int v=x*2;
            if(v<n) t.push_back(v);
        }
        for(int x:s){
            int v=x*2+1;
            if(v<n) t.push_back(v);
        }
        s.swap(t);
    }

    for(int i=0;i<n;i++){
        if(i) std::cout<<" ";
        std::cout<<(s[i]+1);
    }
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
