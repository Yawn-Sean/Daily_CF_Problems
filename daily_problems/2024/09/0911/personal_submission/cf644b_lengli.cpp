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
    int n,len;
    std::cin>>n>>len;
    std::vector<std::array<int,2>> a(n+2);
    for(int i=1;i<=n;i++){
        auto &[l,r]=a[i];
        std::cin>>l>>r;
    }
    std::queue<std::array<int,2>> q;
    q.push({1,a[1][0]+a[1][1]});
    std::vector<int> res(n+2,-1);
    int j=2,la=0;
    while(q.size()){
        auto [id,t]=q.front();
        q.pop();
        int mx=std::max(t,la+a[id][1]);
        while(j<=n and a[j][0]<=mx){
            auto ed=a[j][0]+a[j][1];
            if(a[j][0]==mx){
                if(q.size()<=len) q.push({j,ed});
            }else if(q.size()<len) q.push({j,ed});
            j++;
        }
        res[id]=mx;
        la=mx;

        if(q.empty() and j<=n){
            auto ed=a[j][0]+a[j][1];
            q.push({j,ed});
            j++;
        }
    }
    for(int i=1;i<=n;i++) std::cout<<res[i]<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
