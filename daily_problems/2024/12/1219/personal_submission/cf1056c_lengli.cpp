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
    std::vector<int> a(n*2+2);
    for(int i=1;i<=n*2;i++) std::cin>>a[i];
    std::map<int,int> q;
    std::vector<std::array<int,2>> pp(k);
    for(auto &[u,v]:pp){
        std::cin>>u>>v;
        q[u]=v;
        q[v]=u;
    }
    std::vector<int> id;
    for(int i=1;i<=n*2;i++) id.pb(i);
    
    sort(all(id),[&](auto &l,auto &r){
        return a[l]<a[r];
    });

    int turn;
    std::cin>>turn;
    turn--;

    std::set<int> s;

    auto print=[&](int x){
        std::cout<<x<<std::endl;
    };

    auto wtf=[&](int len){
        turn=0;
        for(int i=0;i<len;i++,turn^=1){
            if(turn){
                int x;
                std::cin>>x;
                s.insert(x);
            }else{
                int t=-1;
                while(pp.size()){
                    auto [u,v]=pp.back();
                    pp.pop_back();
                    if(a[u]<a[v]) std::swap(u,v);
                    if(s.count(u)) continue;
                    t=u;
                    break;
                }
                if(t==-1){
                    while(id.size()){
                        auto x=id.back();
                        id.pop_back();
                        if(s.count(x)) continue;
                        print(x);
                        s.insert(x);
                        break;
                    }
                }else{
                    print(t);
                    s.insert(t);
                }
            }
        }
    };

    if(turn==1){
        int la=-1;
        for(int i=0;i<n*2;i++,turn^=1){
            if(turn){
                int x;
                std::cin>>x;
                s.insert(x);
                la=x;
            }else{
                if(q.count(la)){
                    int x=q[la];
                    if(!s.count(x)){
                        print(x);
                        s.insert(x);
                        la=x;
                        continue;
                    }
                }
                wtf(n*2-i);
                break;
            }
        }
    }else wtf(n*2);
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
