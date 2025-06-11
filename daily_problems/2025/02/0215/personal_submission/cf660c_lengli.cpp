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
    int n,k;
    std::cin>>n>>k;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    int res=-1,l=-1,r=-1;
    for(int i=1,j=0,cnt=0;i<=n;cnt-=(a[i]==0),i++){
        while(cnt<=k and j<=n){
            j++;
            cnt+=(a[j]==0);
        }
        if(j-i>res){
            res=j-i,l=i,r=j;
        }
    }
    std::cout<<res<<"\n";
    for(int i=1;i<=n;i++){
        if(i>=l and i<r) std::cout<<1<<" ";
        else if(a[i]) std::cout<<1<<" ";
        else std::cout<<0<<" ";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
