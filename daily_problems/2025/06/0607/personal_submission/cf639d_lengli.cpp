/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr i64 inf=2e18;

void solve(){
    int n,k,b,c;
    std::cin>>n>>k>>b>>c;
    b=std::min(b,5*c);

    std::vector<int> a(n);
    for(auto &x:a) std::cin>>x; 
    sort(all(a));

    i64 res=inf;

    for(int mod=0;mod<5;mod++){
        std::priority_queue<i64> q;

        i64 sum=0;
        
        for(auto x:a){
            i64 val=0;
            while((x-mod)%5) val+=c,x++;

            i64 cnt=(x-mod)/5;

            q.push(val-cnt*b);
            sum+=val-cnt*b;
            while(q.size()>k){
                sum-=q.top();
                q.pop();
            }
            
            if(q.size()==k){
                i64 ans=1ll*cnt*b*k+sum;
                res=std::min(res,ans);
            }
        }
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
