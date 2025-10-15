/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct BIT{
    int mn;
    std::vector<int> a;
    BIT(){};
    BIT(int n){
        a.clear(),a.resize(n+2);
        mn=n;
    };
    int lowbit(int x){return x&-x;}
    void add(int x,int c) {for(int i=x;i<=mn;i+=lowbit(i)) a[i]=std::max(a[i],c);}
    int sum(int x){
        int res=0;
        for(int i=x;i;i-=lowbit(i)) res=std::max(a[i],res);
        return res;
    }
};

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> cnt(m+2);
    for(int i=1;i<=n;i++){
        int l,r;
        std::cin>>l>>r;
        cnt[l]++;
        cnt[r+1]--;
    }
    for(int i=1;i<=m;i++){
        cnt[i]+=cnt[i-1];
    }

    auto get=[&](){
        std::vector<int> ans(m+2,0);
        BIT tr(n+2);
        for(int i=1;i<=m;i++){
            int v=cnt[i]+1;
            ans[i]=tr.sum(v)+1;
            tr.add(v,ans[i]);
        }
        return ans;
    };

    auto pre=get();
    reverse(all(cnt));
    auto suf=get();
    reverse(all(suf));
    
    int res=0;
    for(int i=1;i<=m;i++){
        res=std::max(res,pre[i]+suf[i]-1);
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
