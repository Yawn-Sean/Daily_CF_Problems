/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1e9;

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::string> s(n);
    for(auto &x:s) std::cin>>x;
    sort(all(s));
    s.erase(std::unique(all(s)),s.end());
    n=s.size();

    std::vector<char> q={'R','G','B','Y','W','1','2','3','4','5'};
    std::vector<char> tmp;

    auto check=[&]()->bool{
        std::vector<std::vector<std::string>> f,g;
        f.pb(s);
        for(auto x:tmp){
            g.clear();
            for(auto t:f){
                std::vector<std::string> l,r;
                for(auto v:t){
                    if(v[0]==x or v[1]==x) l.pb(v);
                    else r.pb(v);
                }
                if(l.size()) g.pb(l);
                if(r.size()) g.pb(r);
            }
            f.swap(g);
        }
        return f.size()==n;
    };

    int res=inf;
    for(int i=0;i<(1<<10);i++){
        int cnt=0;
        tmp.clear();
        for(int j=0;j<10;j++){
            if(i>>j&1){
                tmp.pb(q[j]);
                cnt++;
            }
        }
        if(check()) res=std::min(res,cnt);
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
