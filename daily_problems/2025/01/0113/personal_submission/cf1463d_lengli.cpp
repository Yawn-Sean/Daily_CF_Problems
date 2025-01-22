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
    int cnt=0,k=0;
    int res=n+1;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=n;i++){
        cnt+=a[i]-a[i-1]-1;
        cnt--;
        if(cnt<0) cnt=0,res--;
    }
    cnt=0,a[n+1]=n*2+1;
    for(int i=n;i>=1;i--){
        cnt+=a[i+1]-a[i]-1;
        cnt--;
        if(cnt<0) cnt=0,res--;
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
