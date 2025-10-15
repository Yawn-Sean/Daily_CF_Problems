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
    std::vector<std::array<int,3>> seg;
    for(int i=1;i<=n;i++){
        int h,l,r;
        std::cin>>h>>l>>r;
        seg.pb({l,h,1});
        seg.pb({r,h,-1});
    }
    sort(all(seg));

    int la=0,lidx=-2000000000;
    std::multiset<int> s={0};

    std::vector<std::array<int,2>> res;

    for(int i=0;i<seg.size();i++){
        auto [idx,h,flag]=seg[i];
        if(flag==1) s.insert(h);
        else s.erase(s.find(h));
        if(i+1<seg.size() and idx==seg[i+1][0]) continue;
        int v=*s.rbegin();
        if(v!=la){
            res.pb({idx,la});
            res.pb({idx,v});
            la=v;
        }
    }

    std::cout<<res.size()<<"\n";
    for(auto [x,y]:res) std::cout<<x<<" "<<y<<"\n";
}

signed main(){
    fastio;

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
