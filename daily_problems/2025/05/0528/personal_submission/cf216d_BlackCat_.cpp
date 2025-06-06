#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n;
    std::cin>>n;
    std::vector a(n,std::vector<int>());
    int k,x;

    for(int i=0;i<n;i++){
        std::cin>>k;
        for(int j=0;j<k;j++){
            std::cin>>x;
            a[i].emplace_back(x);
        }
        std::sort(a[i].begin(),a[i].end());
    }
    int ans=0;
    auto get=[&](int id,int l,int r)->int{
        return std::lower_bound(a[id].begin(),a[id].end(),r)-std::lower_bound(a[id].begin(),a[id].end(),l);
    };
    for(int i=0;i<n;i++){
        // std::vector<int> pre(1e5+10),pre1(1e5+10);
        int ls=(i-1+n)%n;
        int next=(i+1)%n;
        for(int j=1;j<a[i].size();j++){
            if(get(ls,a[i][j-1],a[i][j])!=get(next,a[i][j-1],a[i][j])){
                ans++;
            }
        }
        // for(auto x:a[ls]){
        //     pre[x]++;
        // }
        // for(auto x:a[next]){
        //     pre1[x]++;
        // }
        // for(int j=1;j<1e5;j++){
        //     pre[j]+=pre[j-1];
        //     pre1[j]+=pre1[j-1];
        // }
        // for(int j=1;j<a[i].size();j++){
        //     if(pre[a[i][j]]-pre[a[i][j-1]]!=pre1[a[i][j]]-pre1[a[i][j-1]]){
        //         ans++;
        //     }
        // }
    }
    std::cout<<ans<<endl;
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
