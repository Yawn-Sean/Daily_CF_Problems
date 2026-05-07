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
    std::vector<int> mi(10,0);
    for(int i=0;i<10;i++){
        i64 v=i==0 ? 1 : 0;
        for(int j=1;v<=n;j++){
            v*=10,v+=i;
            if(v<=n) mi[i]=j;
        }
    }
    int res=0;
    for(int i=0;i<10;i++) res+=mi[i];
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
