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
    std::map<int,std::vector<std::pair<std::string,int>>> q;
    for(int i=1;i<=n;i++){
        std::string t,s;
        std::cin>>t>>s;
        int st=0;
        for(auto x:s){
            int v=x-'a';
            st|=(1<<v);
        }
        while(t.size()){
            int v=t.back()-'a';
            if(st>>v&1) t.pop_back();
            else break;
        }
        if(t.empty()) t+='*';
        q[st].pb(std::make_pair(t,i));
    }
    std::vector<std::vector<int>> res;
    for(auto &[_,t]:q){
        sort(all(t));
        std::vector<int> ans;
        int len=t.size();
        for(int i=0;i<len;i++){
            if(!i) ans.pb(t[i].second);
            else if(t[i].first==t[i-1].first){
                ans.pb(t[i].second);
            }else{
                res.pb(ans);
                ans.clear();
                ans.pb(t[i].second);
            }
        }
        if(ans.size()) res.pb(ans);
    }
    std::cout<<res.size()<<"\n";
    for(auto x:res){
        std::cout<<x.size()<<" ";
        for(auto y:x) std::cout<<y<<" ";
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
