/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n,c;
    std::cin>>n>>c;
    std::vector<i64> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::priority_queue<std::array<i64,2>,std::vector<std::array<i64,2>>,std::greater<>> q;
    for(int i=2;i<=n;i++){
        q.push({1ll*c*i-a[i],i});
    }
    bool flag=1;
    while(q.size()){
        auto [v,i]=q.top();
        q.pop();
        if(a[1]+a[i]>=i*c){
            a[1]+=a[i];
        }else{
            flag=0;
            break;
        }
    }
    std::cout<<(flag ? "Yes" : "No")<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
