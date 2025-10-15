#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 =long long;
using d64= double;
using ld64= long double;
#define endl '\n'

void solve()
{
    i64 n,k;
    std::cin>>n>>k;
    if(n*(n-1)/2<k){
        std::cout<<"Impossible"<<endl;
        return;
    }
    std::vector<char> ans;
    auto dfs=[&](this auto&&self,i64 u,i64 k)->void{
        if(u==0){
            return ;
        }
        if(k>=u-1){
            std::cout<<"(";
            self(u-1,k-(u-1));
            std::cout<<")";
        }
        else{
            std::cout<<"()";
            self(u-1,k);
        }
    };
    dfs(n,k);
}
signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    solve();
    return 0;
}
