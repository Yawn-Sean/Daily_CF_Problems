/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

void solve(){
    int n,d;
    std::cin>>n>>d;
    std::vector<int> a(n+2),b(n+2,0),ne(n+2,-1e18);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        b[i]=b[i-1]+a[i];
    }

    for(int i=n;i>=1;i--){
        ne[i]=std::max(ne[i+1],b[i]);
    }

    int sum=0,cnt=0;
    bool flag=1;
    for(int i=1;i<=n;i++){
        int v=b[i]+sum;
        if(a[i]){
            if(v>d) flag=0;
        }else {
            if(v<0){
                sum+=std::min(d-v,d-(ne[i+1]+sum));
                if(b[i]+sum<0) flag=0;
                cnt++;
            }
        }
    }
    if(flag) std::cout<<cnt;
    else std::cout<<"-1";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
