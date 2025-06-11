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
    std::set<int> a,b;
    std::vector<std::vector<int>> eg(n+2);
    for(int i=1;i<n;i++){
        int u,v;
        std::cin>>u>>v;
        eg[u].pb(v);
        eg[v].pb(u);
    }
    int ka,kb;
    std::cin>>ka;
    for(int i=1;i<=ka;i++){
        int x;
        std::cin>>x;
        a.insert(x);
    }
    std::cin>>kb;
    for(int i=1;i<=kb;i++){
        int x;
        std::cin>>x;
        b.insert(x);
    }

    auto query=[&](int x,int u){
        std::cout<<(x ? 'A' : 'B')<<" "<<u<<std::endl;
        int res;
        std::cin>>res;
        return res;
    };
    auto print=[&](int x){
        std::cout<<"C"<<" "<<x<<std::endl;
        return;
    };

    auto t=query(0,*b.begin());
    if(a.count(t)){
        print(t);
        return;
    }
    std::queue<int> q;q.push(t);
    std::vector<int> st(n+2);
    while(q.size()){
        auto u=q.front();
        q.pop();
        if(a.count(u)){
            auto ans=query(1,u);
            if(b.count(ans)) print(u);
            else print(-1);
            break;
        }
        if(st[u]) continue;
        st[u]=1;
        for(auto x:eg[u]) q.push(x);
    }

}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
