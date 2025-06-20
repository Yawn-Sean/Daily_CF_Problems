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
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];

    auto check=[&](int x)->bool{
        int v=std::sqrt(x);
        return v*v==x;
    };

    auto cal=[&](int x)->int{
        int v=std::sqrt(x);
        return std::min(x-v*v,(v+1)*(v+1)-x);
    };

    auto rcal=[&](int x)->int{
        if(check(x)){
            if(x-1>=0 and !check(x-1)) return 1;
            if(!check(x+1)) return 1;
            if(!check(x+2)) return 2;
            if(x-2>=0 and !check(x-2)) return 2; 
        }
        return 0;
    };

    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=check(a[i]);

    if(cnt==n/2){
        std::cout<<0<<"\n";
        return;
    }else if(cnt<n/2){
        std::vector<int> q;
        for(int i=1;i<=n;i++) q.pb(cal(a[i]));
        sort(all(q));
        i64 res=0;
        for(int i=0;i<n/2;i++) res+=q[i];
        std::cout<<res<<"\n";
    }else{
        std::vector<int> q;
        for(int i=1;i<=n;i++) q.pb(rcal(a[i]));
        sort(all(q));
        i64 res=0;
        for(int i=0;i<n/2;i++) res+=q[i];
        std::cout<<res<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
