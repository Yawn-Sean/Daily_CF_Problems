#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using d64=double;
using ld64=long double;
void solve(){
    int n;
    std::cin>>n;
    std::vector pq(n,std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<>>());
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        pq[i].push({ x,i });
    }
    std::vector<int> ans(n);
    std::vector e(n,std::vector<std::pair<int,int>>());
    int u,v,c;
    for(int i=1;i<n;i++){
        std::cin>>u>>v>>c;
        u--;
        v--;
        e[u].push_back({ v,c });
        e[v].push_back({ u,c });
    }
    int flag=1;
    int day=0;
    auto dfs=[&](this auto&& self,int u,int fu,int c)->void{
        if(fu!=-1){
            int cnt=0;
            while(!pq[u].empty()&&cnt<c){
                flag=1;
                cnt++;
                pq[fu].push(pq[u].top());
                pq[u].pop();
            }
        }
        for(auto [v,c1]:e[u]){
            if(v==fu){
                continue;
            }
            self(v,u,c1);
        }
        if(fu==-1){
            while(!pq[u].empty()){
                auto [x,y]=pq[u].top();
                pq[u].pop();
                ans[y]=day;
            }
            return;
        }

        return;
        };

    while(flag){
        flag=0;
        day++;
        dfs(0,-1,0);
    }
    ans[0]=0;
    for(auto x:ans){
        std::cout<<x<<" ";
    }
    std::cout<<endl;
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
