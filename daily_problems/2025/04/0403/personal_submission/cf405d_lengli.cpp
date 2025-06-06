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
    std::vector<int> st(2000010,0),flag(2000010,0);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        flag[a[i]]=1;
    }
    std::vector<int> res;
    int s=1000000;
    for(int i=1,j=1;i<=n;i++){
        if(st[a[i]]) continue;
        if(!flag[s+1-a[i]]) res.pb(s+1-a[i]);
        else{
            while(flag[j] or flag[s+1-j]) j++;
            res.pb(j);
            res.pb(s+1-j);
            st[s+1-a[i]]=1;
            j++;
        }
    }
    std::cout<<res.size()<<"\n";
    for(auto x:res) std::cout<<x<<" ";
    std::cout<<"\n"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
