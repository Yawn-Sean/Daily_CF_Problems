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
    std::vector<std::vector<int>> res;
    std::vector<int> tmp;
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        if(tmp.empty()) tmp.pb(x);
        else{
            if(x==1) tmp.pb(x);
            else{
                while(tmp.size() and x!=tmp.back()+1) tmp.pop_back();
                if(tmp.size() and x==tmp.back()+1) tmp.pop_back();
                tmp.pb(x);
            }
        }
        res.pb(tmp);
    }
    for(auto x:res){
        std::cout<<x[0];
        for(int i=1;i<x.size();i++){
            std::cout<<"."<<x[i];
        }
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
