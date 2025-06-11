/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

void solve(){
    int n;
    std::cin>>n;

    int cnt,hs;
    std::cin>>cnt>>hs;
    std::vector<std::array<int,2>> team(n-1);
    for(auto &[x,y]:team) std::cin>>x>>y;
    sort(all(team),std::greater<>());

    std::priority_queue<int,std::vector<int>,std::greater<int>> q;

    int idx=0;
    while(idx<n-1 and team[idx][0]>cnt) {
        q.push({team[idx][1]-team[idx][0]+1});
        idx++;
    }
    int res=q.size()+1;

    while(cnt and q.size()){
        auto t=q.top();
        q.pop();
        if(cnt<t) break;
        cnt-=t;
        while(idx<n-1 and team[idx][0]>cnt) {
            q.push({team[idx][1]-team[idx][0]+1});
            idx++;
        }
        res=std::min(res,(int)q.size()+1);
    }

    std::cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
