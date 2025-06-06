#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
void solve(){
    std::vector<int> a(3),b(3);
    for(int i=0;i<3;i++){
        std::cin>>a[i]>>b[i];
        
    }
    if(a[0]==a[1]&&a[1]==a[2]){
        std::cout<<1<<endl;
        return ;
    }
    if(b[0]==b[1]&&b[1]==b[2]){
        std::cout<<1<<endl;
        return ;
    }
    auto check =[&](int i,int j,int k)->bool{
        return ((a[k] == a[i] || a[k] == a[j]) &&(std::min(b[i],b[j])<=b[k]&&std::max(b[i],b[j])>=b[k]))||
           ((b[k] == b[i] || b[k] == b[j]) &&(std::min(a[i],a[j])<=a[k]&&std::max(a[i],a[j])>=a[k]));
    };
    if(check(0,1,2)||check(0,2,1)||check(1,2,0)){
        std::cout<<2<<endl;
        return ;
    }
    std::cout<<3<<endl;
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
