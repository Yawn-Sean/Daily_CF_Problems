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
    std::map<int,int> mark;
    for(int i=0;i<n*n;i++){
        int x;
        std::cin>>x;
        mark[x]++;
    }
    std::priority_queue<std::array<int,2>> q;
    for(auto [x,y]:mark) q.push({y,x});
    int pt=0;
    std::vector<std::set<std::array<int,2>>> hv;
    for(int i=1;i<=(n+1)/2;i++){
        for(int j=1;j<=(n+1)/2;j++){
            int laR=n-i+1;
            int laC=n-j+1;
            std::set<std::array<int,2>> st;
            st.insert({i,j});
            st.insert({i,laC});
            st.insert({laR,j});
            st.insert({laR,laC});
            hv.pb(st);
        }
    }
    std::sort(all(hv),[&](auto x,auto y){
        return x.size()>y.size();
    });

    std::vector<std::vector<int>> res(n+1,std::vector<int>(n+1));

    for(auto x:hv){
        if((int)x.size()>q.top()[0]){
            std::cout<<"NO"<<"\n";
            return;
        }
        auto t=q.top();
        q.pop();
        t[0]-=x.size();
        if(t[0]>0){
            q.push(t);
        }
        for(auto [i,j]:x){
            res[i][j]=t[1];
        }
    }
    std::cout<<"YES"<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            std::cout<<res[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
