#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    if(n<3||n%2==0){
        std::cout<<-1<<endl;
        return ;
    }
    int  ans=0;
    auto dfs=[&](this auto &&self,int i)->int{
        int t=0;
        if(2*i<=n){
            t=std::max(t,self(2*i));
        }
        if(2*i+1<=n){
            t=std::max(t,self(2*i+1));
        }
        ans+=t;
        a[i]-=t;
        return a[i];
    };
    i64 f=std::max(0,dfs(1));
    ans+=f;
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
