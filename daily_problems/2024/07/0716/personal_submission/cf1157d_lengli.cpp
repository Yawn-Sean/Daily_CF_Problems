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
    int n,k;
    std::cin>>n>>k;
    std::vector<int> res(k+2);
    if(1ll*(k+1)*k/2>n) {
        std::cout<<"NO"<<"\n";
        return;
    }else{
        res[0]=1e9;
        int sum=0,add=0;
        for(int i=1;i<=k;i++) res[i]=i,sum+=i;
        for(int i=1;i<=k;i++){
            int cnt=k-i+1,d=n-sum;
            res[i]+=add;
            if(d==0) continue;
            else{
                int dta=std::min(2*res[i-1]-res[i],d/cnt);
                res[i]+=dta;
                add+=dta;
                sum+=cnt*dta;
            }
        }
    }
    int sum=0;
    for(int i=1;i<=k;i++) sum+=res[i];
    std::cout<<(sum==n ? "YES" : "NO")<<"\n";
    if(sum==n) for(int i=1;i<=k;i++) std::cout<<res[i]<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
