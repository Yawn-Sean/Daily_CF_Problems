/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

int a[10]={0,0,1,7,4,2,6,8,0,0};

void solve(){
    int n;
    std::cin>>n;
    if(n==6){
        std::cout<<0<<"\n";
        return;
    }
    if(n<=7){
        std::cout<<a[n]<<"\n";
        return;
    }
    int v=n%7;
    std::string res=std::string(n/7,'8');
    if(v==1){
        res[0]='0';
        std::cout<<1<<res<<"\n";
    }else if(v==6){
        std::cout<<6<<res<<"\n";
    }else if(v==2){
        std::cout<<1<<res<<"\n";
    }else if(v==3){
        if(res.size()>=2) {
            res[0]='0',res[1]='0';
            std::cout<<2<<res<<"\n";
        }else{
            res[0]='2';
            std::cout<<2<<res<<"\n";
        }
    }else if(v==4){
        res[0]='0';
        std::cout<<2<<res<<"\n";
    }else if(v==5){
        std::cout<<2<<res<<"\n";
    }else std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
