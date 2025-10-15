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
    int n,m;
    std::cin>>n>>m;
    std::vector<int> st(n+2,1);
    std::vector<std::pair<char,int>> q(m);

    int leader=-1;

    for(auto &[c,x]:q){
        std::cin>>c>>x;
        if(c=='+' and leader==-1){
            leader=x;
        }
        if(c=='-' and st[x]){
            leader=x;
        }
        st[x]=0;
    }

    std::set<int> s={leader};
    st[leader]=1;

    for(auto [c,x]:q){
        if(c=='-') s.erase(x);
        else s.insert(x);
        if(s.size() and !s.count(leader)) st[leader]=0;
    }

    int res=0;
    for(int i=1;i<=n;i++) res+=st[i];
    std::cout<<res<<"\n";
    for(int i=1;i<=n;i++){
        if(st[i]) std::cout<<i<<" ";
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
