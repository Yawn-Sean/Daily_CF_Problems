/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

std::vector<int> q[200010];

struct BIT{
    int mn;
    std::vector<int> a;
    BIT(){};
    BIT(int n){
        a.clear(),a.resize(n+2);
        mn=n;
    };
    int lowbit(int x){return x&-x;}
    void add(int x,int c) {for(int i=x;i<=mn;i+=lowbit(i)) a[i]+=c;}
    long long sum(int x){
        long long res=0;
        for(int i=x;i;i-=lowbit(i)) res+=a[i];
        return res;
    }
};

void solve(){
    for(int i=1;i<=200000;i++)
        for(int j=i;j<=200000;j+=i) q[i].pb(j);
    int n;
    std::cin>>n;
    BIT tr(200010);
    std::vector<int> a(n);
    std::vector<int> cnt(200010);
    for(auto &x:a) {
        std::cin>>x;  
        cnt[x]++;
    }
    auto get=[&](int x){
        long long ans=0,sum=0;
        for(int i=q[x].size()-1;i>=0;i--){
            int v=q[x][i];
            if(v<x) break;
            int cnt=n-tr.sum(v-1);
            cnt-=sum;
            ans+=1ll*v*cnt;
            sum+=cnt;
        }
        return ans;
    };
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    for(auto x:a) tr.add(x,cnt[x]);
    long long res=0;
    for(auto x:a) res=std::max(res,get(x));
    std::cout<<res<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
