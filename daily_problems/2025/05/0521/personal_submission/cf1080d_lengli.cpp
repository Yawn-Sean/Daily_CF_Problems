/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

i64 qmi(i64 a,i64 b){
    i64 res=1;
    while(b){
        if(b&1) res*=a;
        a*=a;
        b/=2;
    }
    return res;
}

void solve(){
    i64 n,k;
    std::cin>>n>>k;
    if(n>=32){
        std::cout<<"YES "<<n-1<<"\n";
        return;
    }

    auto get=[&](int x){
        return (qmi(4,x)-1)/3;
    };

    i64 mi=0,mx=0,tmp=1;
    for(int i=n-1;i>=0;i--){
        mi+=(1<<n-i)-1;
        mx+=tmp*get(i);
        tmp--;
        tmp*=2;
        tmp+=5;
        if(mi<=k and k<=mi+mx){
            std::cout<<"YES "<<i<<"\n";
            return;
        }
        if(k<mi){
            std::cout<<"NO"<<"\n";
            return;
        }
    }
    std::cout<<"NO"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
