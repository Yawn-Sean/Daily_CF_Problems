/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1e9;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2),b(n+2);
    std::multiset<int> s;
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        a[x]=i;
    }
    for(int i=0;i<n;i++){
        std::cin>>b[i];
        s.insert(i-a[b[i]]);
    }
    for(int i=0;i<n;i++){
        auto it=s.lower_bound(i);
        int res=inf;
        if(it!=s.end()){
            res=std::min(res,*it-i);
        }
        if(it!=s.begin()){
            res=std::min(res,i-*prev(it));
        }
        std::cout<<res<<"\n";
        it=s.find(i-a[b[i]]);
        s.erase(it);
        s.insert(i-a[b[i]]+n);
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
