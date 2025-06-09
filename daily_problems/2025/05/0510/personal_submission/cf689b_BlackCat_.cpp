#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n);
    std::vector e(n,std::vector<int>());
    for(int i=0;i<n-1;i++){
        e[i].emplace_back(i+1);
        e[i+1].emplace_back(i);
    }
    for(int i=0;i<n;i++){
        std::cin>>a[i];
        a[i]--;
        e[i].push_back(a[i]);
    }
    std::vector<int> ans(n,1e9);
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<>> q;
    q.push({0,0});
    while(!q.empty()){
        auto [x,y]=q.top();
        q.pop();
        if(ans[y]!=1e9){
            continue;
        }
        ans[y]=x;
        for(auto v:e[y]){
            q.push({x+1,v});
        }
    }
    for(int i=0;i<n;i++){
        std::cout<<ans[i]<<" ";
    }
    
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
