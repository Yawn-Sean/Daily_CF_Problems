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
    std::string s;
    std::cin>>s;
    int n;
    std::cin>>n;

    std::vector<std::string> a(n);
    for(auto &x:a) std::cin>>x;

    int res=0,pos=0;

    int l=0,r=0;

    while(l<s.size()){
        for(auto x:a){
            int t=r-x.size()+1;
            if(t>=l and s.substr(t,x.size())==x){
                l=std::max(l,t+1);
            }
        }
        if(r-l+1>res){
            res=r-l+1;
            pos=l;
        }
        if(r!=s.size()-1) r++;
        else l++;
    }
    std::cout<<res<<" "<<pos<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
