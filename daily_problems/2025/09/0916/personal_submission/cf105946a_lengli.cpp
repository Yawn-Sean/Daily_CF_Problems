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
    std::vector<i64> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::map<i64,int> q;
    for(int i=1;i<=n;i++) q[a[i]]++;
    i64 res=0;
    if(q[1]>=2 and q[2]>=1){
        res+=1ll*q[1]*(q[1]-1)*q[2];
    }
    if(q[2]>=2 and q[4]>=1){
        res+=1ll*q[2]*(q[2]-1)*q[4];
    }
    if(q[1]>=1 and q[2]>=1 and q[3]>=1){
        res+=1ll*q[1]*q[2]*q[3]*2;
    }
    if(q[1]>=1 and q[3]>=1 and q[4]>=1){
        res+=1ll*q[1]*q[3]*q[4]*2;
    }
    
    for(auto [x,y]:q){
        if(x<=4) continue;
        res+=1ll*y*q[2]*q[x-2]*2;
        res+=1ll*y*q[4]*q[x-4]*2;
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
