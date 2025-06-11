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
    std::vector<int> p(n+2),b(n+2);
    for(int i=1;i<=n;i++) std::cin>>p[i];
    int res=1;
    for(int i=1;i<=n;i++) std::cin>>b[i],res^=b[i];
    
    std::vector<int> st(n+2);
    int k=0;
    for(int i=1;i<=n;i++){
        if(!st[i]){
            int idx=i;
            st[idx]=1;idx=p[idx];
            while(!st[idx]){
                st[idx]=1;
                idx=p[idx];
            }
            k++;
        }
    }
    if(k>1) res+=k;
    std::cout<<res<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
