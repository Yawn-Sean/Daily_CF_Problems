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
    if(n%4==3) std::cout<<"-1"<<"\n";
    else{
        std::vector<int> res(n);
        for(int i=0;i<n;i++) res[i]=i+1;
        for(int i=3;i<n;i+=4){
            std::swap(res[i-1],res[i]);
        }
        for(int i=0;i<n;i++) std::cout<<res[i]<<" ";
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
