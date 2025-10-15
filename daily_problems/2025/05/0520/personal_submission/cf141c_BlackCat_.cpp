#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n;
    std::cin>>n;
    std::vector<std::string > a[n+1];
    std::string s;
    int x;
    for(int i=0;i<n;i++){
        std::cin>>s>>x;
        a[x].emplace_back(s);
    
    }
    int now=1e8;
    std::vector<std::pair<std::string ,int>> ans;
    for(int i=0;i<n;i++){
        if(i>ans.size()){
            std::cout<<-1<<endl;
            return ;
        }
        for(auto x:a[i]){
            ans.insert(ans.begin()+i,{x,--now});
        }
    }
    for(auto [x,y]:ans){
        std::cout<<x<<" "<<y<<endl;
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
