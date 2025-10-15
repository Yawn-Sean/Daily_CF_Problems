#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    i64 n;
    std::cin>>n;
    n=n%360;
    n=-n;
    n+=360;
    n%=360;
    std::map<int,int> mp;
    auto get=[&](i64 u)->i64{
        u%=360;
        if(u<0){
            return std::min(360+u,-u);
        }
        else{
            return std::min(u,360-u);
        }
    };
    mp[n]=0;
    i64 maxn=get(n);
    i64 ans=0;
    for(int i=1;;i++){
        i64 t=get(n+90);
        n=n+90;
        n%=360;
        if(mp.find(n)!=mp.end()){
            break;
        }
        mp[n]=i;
        if(t<maxn){
            ans=i;
            maxn=t;
        }
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
