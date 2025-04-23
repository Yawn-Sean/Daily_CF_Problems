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
    std::vector<std::string> s(2*n-2);
    for(auto &x:s) std::cin>>x;
    bool flag=0;
    std::string a="a",b="b";
    std::string pre="";
    for(auto x:s){
        if(x.size()==n-1 and !flag) a=x,flag=1;
        else if(x.size()==n-1) b=x;
    }
    int cnt=0;
    for(auto x:s){
        int len=x.size();
        if(a.substr(0,len)==x and x!=b) cnt++;
    }

    if(cnt>=n-1 and a.substr(1,a.size()-1)==b.substr(0,b.size()-1)) pre=a;
    else pre=b;

    std::vector<int> st(n+2,0);
    std::string res="";
    for(auto x:s){
        int len=x.size();
        if(x==pre.substr(0,len) and !st[len]){
            res+='P';
            st[len]=1;
        }else res+='S';
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
