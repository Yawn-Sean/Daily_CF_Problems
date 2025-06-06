#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<int> b(n+1);
    for(int i=1;i<=n;i++){
        std::cin>>b[i];
    }
    std::vector<int> a;
    for(int i=n;i>=1;i--){
        int c=0;
        std::vector<int> ne;
        for(auto &x:a){
            if(c==b[i]){
                ne.emplace_back(i);
                c++;
            }
            ne.emplace_back(x);
            c+=(i+k<=x);
        }
        if (c == b[i]){
            ne.emplace_back(i);
        }
        swap(a, ne);
    }
    for(int i=0;i<n;i++){
        std::cout<<a[i]<<" \n"[i==n-1];
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
