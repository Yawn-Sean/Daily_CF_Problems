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

    if(n==0){
        std::cout<<"a"<<"\n";
        return;
    }

    std::string res="";
    char c='a';

    while(n>0){
        int cnt=1;
        int val=0;
        while(val<n){
            if(val+cnt<=n) val+=cnt,cnt++;
            else break;
        }
        n-=val;
        res+=std::string(cnt,c);
        c++;
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
