/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr long long inf=1e18;

#define int long long

void solve(){
    int n,q;
    std::cin>>n>>q;
    std::vector<std::vector<std::array<int,2>>> seg(n+2);
    std::vector<std::array<int,3>> useg;
    for(int i=1,l=1,r=1;i<=n;i++){
        seg[i].pb({l,r});
        l*=2;r*=2;r++;
    }
    for(int i=1;i<=q;i++){
        int id,l,r,x;
        std::cin>>id>>l>>r>>x;
        auto L=seg[id][0][0],R=seg[id][0][1];
        if(!x) useg.pb({id,l,r});    
        else seg[id].pb({l,r});
    }

    auto merge=[&](int id){
        std::array<int,2> ans={-1,-1};
        sort(all(seg[id]));
        int l=seg[id].back()[0];
        int r=inf;
        for(auto [_,t]:seg[id]) r=std::min(t,r);
        if(l<=r) ans={l,r};
        return ans;

    };

    std::array<int,2> res=merge(1);
    for(int i=2;i<=n;i++){
        res[0]*=2,res[1]*=2,res[1]++;
        seg[i].pb(res);
        res=merge(i);
    }
    if(res[0]==-1) {
        std::cout<<"Game cheated!"<<"\n";
        return;
    }
    std::set<std::array<int,3>> s;
    auto split=[&](int x){
        auto it=s.lower_bound(std::array<int,3>{x,0,0});
        if(it!=s.end() and (*it)[0]==x) return it;
        it=prev(it);
        int l=(*it)[0],r=(*it)[1],v=(*it)[2];
        s.erase(it);
        s.insert(std::array<int,3>{l,x-1,v});
        return s.insert(std::array<int,3>{x,r,v}).first;
    };

    auto assign=[&](int l,int r,int v){
        auto it2=split(r+1),it1=split(l);
        s.erase(it1,it2);
        s.insert(std::array<int,3>{l,r,v});
    };
    s.insert({1ll<<(n-1),(1ll<<n)-1,0});
    assign(res[0],res[1],1);

    for(auto [id,l,r]:useg){
        while(id<n){
            id++;
            l*=2,r*=2;
            r++;
        }
        assign(l,r,0);
    }
    int ans=-1,cnt=0;
    for(auto [l,r,st]:s){
        if(st and l<=r){
            ans=l;
            cnt+=r-l+1;
        }
    }
    if(!cnt) std::cout<<"Game cheated!"<<"\n";
    else if(cnt==1) std::cout<<ans<<"\n";
    else std::cout<<"Data not sufficient!"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
