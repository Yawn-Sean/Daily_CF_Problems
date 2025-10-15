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
    std::vector<int> a(n+2),p(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=n;i++) std::cin>>p[i];
    std::set<std::array<int,2>,std::greater<>> l,r;
    for(int i=1;i<=n;i++) l.insert({a[i],i});
    int res=0,len=0;
    for(int i=1;i<=n;i++){
        if(i>1){
            int idx=p[i-1];
            l.erase({a[idx],idx});
            r.erase({a[idx],idx});
        }
        while(r.size()<i and l.size()){
            auto it=l.begin();
            r.insert(*it);
            l.erase(it);
        }
        if(r.size()==i){
            auto [val,_]=*r.rbegin();
            int ans=val*i;
            if(ans>res){
                res=ans;
                len=i;
            }
        }
    }
    std::cout<<res<<" "<<len<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
