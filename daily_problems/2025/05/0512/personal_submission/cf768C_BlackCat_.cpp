#include<bits/stdc++.h>
#define endl '\n'
using i64=long long;
using u64=unsigned long long;
using d64=double;
using ld64=long double;
void solve(){
    int n,k,x;
    std::cin>>n>>k>>x;
    std::vector<int> a(n);
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
    // std::map<std::pair<int,int>,std::vector<int>> mp;
    // std::sort(a.begin(),a.end());
    // for(int i=0;i<100;i++){
    //     for(int i=0;i<n;i+=2){
    //         a[i]^=x;
    //     }
    //     std::sort(a.begin(),a.end());
    //     mp[{a.back(),a[0]}].push_back(i);
    // }
    // for(auto &[x,y]:mp){
    //     std::cout<<x.first<<" "<<x.second<<endl;
    //     for(auto z:y){
    //         std::cout<<z<<" ";
    //     }
    //     std::cout<<endl;
    // } 
    if(k<=10){
        std::sort(a.begin(),a.end());
        for(int i=0;i<k;i++){
            for(int i=0;i<n;i+=2){
                a[i]^=x;
            }
            std::sort(a.begin(),a.end());
        }
        std::cout<<a.back()<<" "<<a[0]<<endl;
    }
    else{
        int m=k%64;
        std::sort(a.begin(),a.end());
        for(int i=0;i<m;i++){
            for(int i=0;i<n;i+=2){
                a[i]^=x;
            }
            std::sort(a.begin(),a.end());
        }
        std::cout<<a.back()<<" "<<a[0]<<endl;
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
