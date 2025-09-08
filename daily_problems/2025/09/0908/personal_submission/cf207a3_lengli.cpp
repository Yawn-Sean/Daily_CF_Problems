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
    std::vector<std::pair<std::pair<int,int>,int>> v;
    int res=0,sz=0;
    for(int i=1;i<=n;i++){
        int cnt=0;
        std::vector<int> tmp;
        int pos=0;
        i64 k,a,x,y,m;
        std::cin>>k>>a>>x>>y>>m;
        for(int j=0;j<k;j++){
            tmp.pb(a);
            if(v.size()<=200005){
                v.pb({{pos,a},i});
            }
            a=(a*x+y)%m;
            if(a<tmp.back()) pos++;
        }
        for(int j=0;j<k-1;j++){
            if(tmp[j]>tmp[j+1]) cnt++;
        }
        res=std::max(res,cnt);
        sz+=tmp.size();
    }
    std::sort(all(v));
    std::cout<<res<<"\n";
    if(sz>200000){
        return;
    }
    for(auto [x,y]:v){
        std::cout<<x.second<<" "<<y<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
