/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr i64 INF=1e18;
constexpr int inf=2e9;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::vector<i64> q={1,0},p={0,1};
    for(int i=1,t=1;i;i++,t++){
        p.pb(p[t]+p[t-1]);
        q.pb(q[t]+q[t-1]);
        if(p.back()>INF) break;
    }

    std::map<int,int> cnt;
    for(int i=1;i<=n;i++) cnt[a[i]]++;

    auto check=[&](int x,int y)->int{
        std::vector<i64> f={x,y};
        for(int i=2;i;i++){
            f.pb({q[i]*x+p[i]*y});
            if(f.back()>inf or f.back()<inf*-1) break;
        }
        std::vector<i64> hv;
        for(auto x:f){
            if(cnt[x]<=0) break;
            cnt[x]--;
            hv.pb(x);
        }
        for(auto x:hv) cnt[x]++;
        return hv.size();
    };

    int res=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(a[i]==0 and a[j]==0){
                res=std::max(res,cnt[0]);
                continue;
            }
            res=std::max(res,check(a[i],a[j]));
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
