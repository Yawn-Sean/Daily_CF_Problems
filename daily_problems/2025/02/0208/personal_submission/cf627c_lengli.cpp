/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=2e9;

void solve(){
    int d,n,m;
    std::cin>>d>>n>>m;
    if(n>=d){
        std::cout<<0<<"\n";
        return;
    }

    std::vector<std::array<int,2>> gas;
    for(int i=1;i<=m;i++){
        std::array<int,2> t;
        std::cin>>t[0]>>t[1];
        gas.pb(t);
    }
    gas.pb({0,inf});
    gas.pb({d,-1});
    sort(all(gas));

    std::stack<int> q;
    int len=gas.size();
    std::vector<int> ne(len,-1);
    for(int i=len-1;i>=0;i--){
        while(q.size() and gas[q.top()][1]>gas[i][1]) q.pop();
        if(q.size()) ne[i]=q.top();
        q.push(i);
    }

    int oil=n;
    i64 res=0;

    for(int i=0;i<len-1;i++){
        int dist=gas[ne[i]][0]-gas[i][0];
        if(oil>=dist){
            oil-=gas[i+1][0]-gas[i][0];
            continue;
        }else if(dist>=n){
            res+=1ll*gas[i][1]*(n-oil);
            oil=n;
            oil-=gas[i+1][0]-gas[i][0];
        }else{
            res+=1ll*gas[i][1]*(dist-oil);
            oil=dist;
            oil-=gas[i+1][0]-gas[i][0];
        }
        if(oil<0){
            std::cout<<"-1"<<"\n";
            return;
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
