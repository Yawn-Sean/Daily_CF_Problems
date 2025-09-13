#include<bits/stdc++.h>
#define endl '\n'
using i64 =long long;
void solve(){
    int n;
    std::cin>>n;
    std::vector<i64> a(n);
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
    std::vector<std::vector<i64>> v(100);
    for(int i=0;i<n;i++){
        // std::cerr<<__builtin_ctzll(a[i])<<" "<<a[i]<<endl;
        v[__builtin_ctzll(a[i])].push_back(a[i]);
    }
    int ans=1e9;
    for(int i=0;i<100;i++){
        // std::cerr<<v[i]<<endl;
        ans=std::min(ans,n-(int)v[i].size());
    }
    int flag=0;
    std::cout<<ans<<endl;
    for(int i=0;i<100;i++){
        if(flag){
            for(auto x:v[i]){
                std::cout<<x<<" ";
            }
        }
        else{
            if(ans==n-v[i].size()){
                flag=1;
            }
            else{
                for(auto x:v[i]){
                std::cout<<x<<" ";
            }
            }
        }
    }
}
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    solve();
}
