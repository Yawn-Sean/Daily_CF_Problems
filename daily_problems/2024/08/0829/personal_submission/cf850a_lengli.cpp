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
    int n;
    std::cin>>n;
    std::vector<std::array<int,5>> pt(n);
    for(auto &x:pt) for(int j=0;j<5;j++) std::cin>>x[j];
    if(n>=50) std::cout<<0<<"\n";
    else{
        std::vector<int> st(n,1);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++){
                    if(i==j or j==k or k==i) continue;
                    std::array<int,5> l,r;
                    for(int id=0;id<5;id++) l[id]=pt[i][id]-pt[k][id],r[id]=pt[j][id]-pt[k][id];
                    int res=0;
                    for(int i=0;i<5;i++) res+=l[i]*r[i];
                    if(res>0) st[k]=0;
                }
        std::vector<int> res;
        for(int i=0;i<n;i++){
            if(st[i]) res.pb(i+1);
        }
        std::cout<<res.size()<<"\n";
        for(auto x:res) std::cout<<x<<" ";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
