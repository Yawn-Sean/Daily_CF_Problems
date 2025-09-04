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
    std::cin>>m>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    std::vector<int> res(m+2);
    res[1]=1,a[1]--;
    for(int i=2;i<=m;i++){
        int pos=0;
        for(int j=1;j<=n;j++){
            if(a[j]>a[pos] and j!=res[i-1] and j!=res[(i+1)%m]) pos=j;
        }
        if(pos==0){
            std::cout<<"-1"<<"\n";
            return;
        }
        res[i]=pos;
        a[pos]--;
    }
    for(int i=1;i<=m;i++) std::cout<<res[i]<<" ";
    std::cout<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
