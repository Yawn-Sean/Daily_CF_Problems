#include <bits/stdc++.h>
#define ll long long

std::set<int> vis;
int bound = 1e9;

void dfs(int x,int y,ll cur){
    if(cur > bound){
        return;
    }
    vis.insert(cur);
    dfs(x,y,cur * 10 + x);
    dfs(x,y,cur * 10 + y);
}

void solve(){
    vis.insert(0);
    for(int i = 1; i < 10; ++i){
        for(int j = 0;j < 10; ++j){
            dfs(i,j,i);
        }
    }
    int n;
    std::cin >> n;
    int ans = 0;
    for(auto x:vis){
        if(vis.find(n - x) != vis.end()){
            ans++;
        }
    }
    std::cout << (ans + 1) / 2;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // int t;
    // std::cin >> t;
    // while(t--){
        solve();
    // }
    std::cout << std::flush;
    return 0;
}