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
    int n,s;
    std::cin>>n>>s;
    std::vector<std::array<int,3>> q(n);
    long long sum=0,res=0;
    for(auto &[x,a,b]:q) {
        std::cin>>x>>a>>b;
        sum+=x,res+=x*a;
    }
    long long cnt=(sum+s-1)/s,up=0,down=0;
    std::vector<std::array<int,2>> add(n);
    for(int i=0;i<n;i++){
        add[i]={q[i][2]-q[i][1],q[i][0]};
        if(add[i][0]>=0) up+=add[i][1];
        else down+=add[i][1];
    }
    sort(all(add),std::greater<>());

    if((up+s-1)/s+(down+s-1)/s==cnt){
        for(auto [v,x]:add){
            if(v>=0) res+=v*x;
            else break;
        }
    }else{
        long long k=up%s,ans=res;
        for(auto [v,x]:add){
            if(v>=0) ans+=v*x;
            else break;
        }
        for(int i=n-1;i>=0 and k;i--){
            auto [v,x]=add[i];
            if(v>=0){
                if(k>=x) k-=x,ans-=v*x;
                else ans-=k*v,k=0;
            }
        }
        long long cp=res;
        res=std::max(res,ans);
    
        k=down%s,ans=cp;
        for(auto [v,x]:add){
            if(v>=0) ans+=v*x;
            else break;
        }
        for(int i=0;i<=n and k;i++){
            auto [v,x]=add[i];
            if(v<0){
                if(k>=x) k-=x,ans+=v*x;
                else ans+=k*v,k=0;
            }
        }
        res=std::max(res,ans);

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
