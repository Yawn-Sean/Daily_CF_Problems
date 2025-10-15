/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

std::bitset<1000010> st;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x;
    std::sort(all(a));
    std::vector<int> tmp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=1;k<=n;k++){
                int v=(a[j]-a[i])/k;
                if(v*k==a[j]-a[i]){
                    st[v]=1;
                    tmp.pb(v);
                }
            }
        }
    }
    int ans=1;
    while(st[ans]) ans++;
    std::cout<<"YES"<<"\n";
    for(int i=1;i<=n;i++){
        std::cout<<1ll*i*ans<<" ";
    }
    std::cout<<"\n";
    for(auto x:tmp) st[x]=0;
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
