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
    int n,k;
    std::cin>>n>>k;
    std::vector<int> cnt(k+2,0);
    for(int i=0;i<k;i++){
        cnt[i]=n/k+(n%k>=i);
    }
    cnt[0]--;
    int res=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if((i*i+j*j)%k==0) res+=cnt[i]*cnt[j];
        }
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
