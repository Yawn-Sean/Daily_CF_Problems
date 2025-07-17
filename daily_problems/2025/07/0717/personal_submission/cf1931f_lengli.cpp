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
    int n,k;
    std::cin>>n>>k;
    std::vector<std::vector<int>> eg(n+2);
    std::vector<int> rd(n+2);
    for(int i=0;i<k;i++){
        std::vector<int> tmp(n);
        for(auto &x:tmp) std::cin>>x;
        for(int i=1;i<n-1;i++){
            eg[tmp[i]].pb(tmp[i+1]);
            rd[tmp[i+1]]++;
        }
    }

    std::queue<int> q;
    for(int i=1;i<=n;i++){
        if(!rd[i]) q.push(i);
    }

    while(q.size()){
        auto t=q.front();
        q.pop();
        for(auto x:eg[t]){
            rd[x]--;
            if(!rd[x]) q.push(x);
        }
    }
    for(int i=1;i<=n;i++){
        if(rd[i]){
            std::cout<<"NO"<<"\n";
            return;
        }
    }
    std::cout<<"YES"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
