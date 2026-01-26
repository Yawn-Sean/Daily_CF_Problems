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
    int n,m;
    std::cin>>n>>m;
    std::vector<int> a(n*m);
    for(auto &x:a) std::cin>>x;

    std::sort(all(a));
    std::vector<int> la(n*m,-1);
    for(int i=1;i<n*m;i++){
        if(a[i]==a[i-1]) la[i]=la[i-1];
        else la[i]=i;
    }

    for(int i=1;i<=n;i++){
        std::vector<int> res;
        int nd=i,l=0;
        for(int j=1;j<=m;j++){
            int r=l+nd-1;
            if(a[l]==a[r]){
                res.pb(a[l]);
                l=r+1;
            }else{
                int len=nd-(r-la[r]+1);
                nd-=len;
                res.pb(a[r]);
                l=r+1;
            }
        }
        for(auto x:res) std::cout<<x<<" ";
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
