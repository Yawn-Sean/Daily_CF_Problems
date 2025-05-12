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
    int n,k,x;
    std::cin>>n>>k>>x;
    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x;
    std::sort(all(a));
    std::map<std::vector<int>,int> q;
    std::map<int,std::vector<int>> p;
    for(int j=1;j<=k;j++){
        for(int i=0;i<n;i+=2) a[i]=a[i]^x;
        std::sort(all(a));
        if(q[a]){
            int l=k-j;
            int idx=l%(j-q[a])+q[a];
            a=p[idx];
            break;
        }
        q[a]=j;
        p[j]=a;
    }
    int mx=0;
    int mi=1000000000;
    for(auto x:a){
        mx=std::max(mx,x);
        mi=std::min(mi,x);
    }
    std::cout<<mx<<" "<<mi<<"\n";

}

signed main(){
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
