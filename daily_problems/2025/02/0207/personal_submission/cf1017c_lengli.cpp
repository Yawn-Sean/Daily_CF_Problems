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
    std::vector<std::vector<int>> res;
    int D=std::sqrt(n);
    
    for(int i=1,j=1;j<=n;i++){
        std::vector<int> tmp;
        for(int k=0;k<D and j<=n;k++){
            tmp.pb(j);
            j++;
        }
        res.pb(tmp);
    } 
    sort(all(res),[&](auto l,auto r){
        return l[0]>r[0];
    });
    for(auto x:res){
        for(auto y:x) std::cout<<y<<" ";
    }std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
