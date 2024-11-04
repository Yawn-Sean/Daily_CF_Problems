/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    std::vector<int> a;
    a.pb(0);
    for(int i=0;i<5;i++){
        for(int j=(1<<i)-1;j>=0;j--){
            a.pb(a[j]|(1<<2*i));
        }
    }
    std::vector<std::array<int,2>> idx(1025);
    for(int i=0;i<32;i++){
        for(int j=0;j<32;j++) idx[a[i]^(a[j]<<1)]={i+1,j+1};
    }
    int n,q;
    std::cin>>n>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            std::cout<<(a[j]^a[j+1])*2<<" ";
        }
        std::cout<<std::endl;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            std::cout<<(a[i]^a[i+1])<<" ";
        }
        std::cout<<std::endl;
    }

    int mask=0;
    for(int i=1;i<=q;i++){
        int x;
        std::cin>>x;
        mask^=x;
        std::cout<<idx[mask][0]<<" "<<idx[mask][1]<<std::endl;
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
