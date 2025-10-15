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
    i64 n,L,v1,v2;
    std::cin>>n>>L>>v1>>v2;
    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x;

    i64 len=v2*L;
    L=1ll*L*(v1+v2);

    std::map<i64,int> b;
    for(auto x:a){
        i64 l=1ll*x*(v1+v2),r=l+len;
        if(r<=2*L){
            b[l]++;
            b[r]--;
        }else{
            b[l]++;
            b[2*L]--;
            b[0]++;
            b[r-2*L]--;
        }
    }
    b[2*L]+=0;
    std::vector<i64> res(n+1);
    int cnt=0;
    i64 la=0;
    for(auto [idx,v]:b){
        res[cnt]+=idx-la;
        cnt+=v;
        la=idx;
    }
    for(auto x:res){
        std::cout<<std::fixed<<std::setprecision(10)<<(double)x/(double)(2*L)<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
