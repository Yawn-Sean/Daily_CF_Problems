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

    std::vector<int> a(n+2);
    std::vector<std::array<int,2>> q;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        q.pb({a[i],i});
    }

    int is_sort=1;
    for(int i=2;i<=n;i++){
        if(a[i]<a[i-1]) is_sort=0;
    }
    if(is_sort){
        std::cout<<0<<"\n";
        return;
    }

    std::sort(all(q));
    std::vector<int> idx(n+2);

    for(int i=1;i<=n;i++){
        auto [v,t]=q[i-1];
        idx[t]=i;
    }

    int use=-1;

    for(int i=1;i<=n;i++){
        std::string s=std::to_string(a[i]);
        bool flag=1;
        for(auto x:s){
            if(x!='4' and x!='7') flag=0;
        }
        if(flag){
            use=i;
            break;
        }
    }

    if(use==-1){
        std::cout<<"-1"<<"\n";
        return;
    }

    std::vector<std::array<int,2>> res;
    if(idx[use]!=use){
        int l=idx[use],r=use;
        res.pb({l,r});
        std::swap(idx[l],idx[r]);
        std::swap(a[l],a[r]);
        use=l;
    }

    std::vector<int> st(n+2);

    for(int i=1;i<=n;i++){
        if(q[i-1][0]==a[i]) continue;
        std::vector<int> tmp;
        auto d=idx[q[i-1][1]];
        while(!st[d]){
            st[d]=1;
            tmp.pb(d);
            d=idx[d];
        }
        reverse(all(tmp));
        if(tmp.size()) tmp.pb(use);
        int l=use;
        for(auto x:tmp){
            int r=x;
            if(l==r) continue;
            res.pb({l,r});
            std::swap(idx[l],idx[r]);
            std::swap(a[l],a[r]);
            std::swap(l,r);
        }

    }
    std::cout<<res.size()<<"\n";
    for(auto [l,r]:res) std::cout<<l<<" "<<r<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
