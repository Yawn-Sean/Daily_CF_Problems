/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::array<long long,2>> a(n);
    std::map<long long,int> q;
    for(int i=0;i<n;i++) std::cin>>a[i][0],q[a[i][0]]++;
    for(int i=0;i<n;i++) std::cin>>a[i][1];
    std::vector<int> st(n);
    long long res=0;
    for(auto [v,cnt]:q){
        if(cnt>=2){
            for(int i=0;i<n;i++){
                if(!st[i] and (a[i][0]|v)==v){
                    st[i]=1;
                    res+=a[i][1];
                }
            }
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
