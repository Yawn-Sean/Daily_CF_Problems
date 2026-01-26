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
    std::set<std::array<int,2>> s;
    int sum=0;
    for(int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        sum+=x;
        if(x) s.insert({x,i});
    }
    int hv=(sum+1)/2;
    std::vector<int> res;
    int idx=1;
    while(s.size()){
        std::array<int,2> t={2,0};
        auto it=s.begin();
        if(idx%2==0){
            it=s.lower_bound(t);
            if(it==s.end() or (*it)[0]==1){
                break;
            }
        }
        t=*it;
        t[0]--;
        res.pb(t[1]);
        s.erase(it);
        if(t[0]) s.insert(t);
        idx++;
    }
    if(s.size()){
        std::cout<<"NO"<<"\n";
        return;
    }
    std::cout<<"YES"<<"\n";
    for(auto x:res) std::cout<<x<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
