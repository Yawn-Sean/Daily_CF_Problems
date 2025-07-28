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
    std::vector<i64> v(n+2),d(n+2),p(n+2),st(n+2);
    for(int i=1;i<=n;i++){
        std::cin>>v[i]>>d[i]>>p[i];
    }
    std::vector<i64> res;
    for(int i=1;i<=n;i++){
        if(!st[i]){
            res.pb(i);
            int tmp=0;
            i64 g=0;
            for(int j=i+1;j<=n;j++){
                if(!st[j]){
                    p[j]-=g;
                    if(tmp<v[i]) p[j]-=v[i]-tmp;
                    if(p[j]<0){
                        g+=d[j];
                        st[j]=1;
                    }
                    tmp++;
                }
            }
        }
    }
    std::cout<<res.size()<<"\n";
    for(auto x:res) std::cout<<x<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
