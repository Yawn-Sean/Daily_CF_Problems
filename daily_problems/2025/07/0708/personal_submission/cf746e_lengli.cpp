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
    std::cin>>n>>m;
    std::vector<int> a(n),cnt(2,0);
    std::vector<int> q;
    std::set<int> s;
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        a[i]=x;
        if(s.count(x) or cnt[x&1]*2==n) q.pb(i);
        else s.insert(x),cnt[x&1]++;
    }
    int res=0;
    for(int i=1;i<=std::min(n,m);i++){
        if(s.count(i) or cnt[i&1]*2==n) continue;
        if(q.empty()) break;
        int idx=q.back();
        q.pop_back();
        a[idx]=i;
        cnt[i&1]++;
        res++;
    }

    bool flag=1;
    std::map<int,int> t;
    for(auto x:a){
        t[x]++;
        if(t[x]>=2) flag=0;
    }


    if(cnt[0]!=cnt[1] or !flag){
        std::cout<<"-1"<<"\n";
        return;
    }

    std::cout<<res<<"\n";
    for(auto x:a) std::cout<<x<<" ";
    std::cout<<"\n"; 

}

signed main(){
    fastio;

    int T;
    T=1;
    while(T--) solve();

    return 0;
}