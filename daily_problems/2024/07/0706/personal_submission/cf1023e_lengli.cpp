/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<char> l,r;
    int x=1,y=1;

    auto query=[&](int x,int y,int a,int b)->bool{
        std::cout<<"? "<<x<<" "<<y<<" "<<a<<" "<<b<<std::endl;
        std::string res;
        std::cin>>res;
        return res=="YES";
    };

    while(x+y<=n){
        auto flag=query(x+1,y,n,n);
        if(flag) x=x+1,l.pb('D');
        else y=y+1,l.pb('R');
    }
    x=n,y=n;
    while(x+y>n+1){
        auto flag=query(1,1,x,y-1);
        if(flag) y=y-1,r.pb('R');
        else x=x-1,r.pb('D');
    }
    reverse(all(r));
    std::cout<<"! ";
    for(auto x:l) std::cout<<x;
    for(auto x:r) std::cout<<x;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
