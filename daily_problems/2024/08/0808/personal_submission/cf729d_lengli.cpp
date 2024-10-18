/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,a,b,k;
    std::cin>>n>>a>>b>>k;
    std::string s;
    std::cin>>s;
    std::vector<int> q;
    for(int i=1;i<=n;i++){
        char c=s[i-1];
        if(c=='1') continue;
        int idx=i;
        while(idx<=n and s[idx-1]==c) idx++;
        for(int j=i+b-1;j<idx;j+=b) q.pb(j);
        i=idx-1;
    }
    int t=q.size()-a+1;
    std::cout<<t<<"\n";
    for(int i=0;i<t;i++) std::cout<<q[i]<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
