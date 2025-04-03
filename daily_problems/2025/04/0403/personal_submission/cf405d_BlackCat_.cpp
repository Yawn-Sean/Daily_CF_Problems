#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n;
    i64 s=1e6;
    std::cin>>n;
    std::vector x(n,0);
    std::vector cnt(s+1,0);
    for(auto &m:x){
        std::cin>>m;
        cnt[m]=1;
    }
    std::vector<i64> y;
    std::vector<i64> z;
    s++;
    for(int i=0;i<n;i++){
        if(cnt[s-x[i]]==0){
            cnt[s-x[i]]=1;
            y.emplace_back(s-x[i]);
        }
        else{   
            z.push_back(x[i]);
        }
    }
    int w=1;
    for(int i=0;i<z.size()/2;i++){
        while((cnt[w]==1||cnt[s-w]==1)){
            w++;
        }
        if(cnt[w]==0&&cnt[s-w]==0){
            y.emplace_back(w);
            y.emplace_back(s-w);
            cnt[w]=1;
            cnt[s-w]=1;
            w++;
        }
    }
    std::cout<<y.size()<<endl;
    for(auto z1:y){
        std::cout<<z1<<" ";
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
