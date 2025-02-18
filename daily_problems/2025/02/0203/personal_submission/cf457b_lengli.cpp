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
    int n,m;
    std::cin>>n>>m;
    std::vector<int> a(n),b(m);
    for(auto &x:a) std::cin>>x;
    for(auto &x:b) std::cin>>x;
    sort(all(a)),sort(all(b));
    i64 res=0,sum=0;
    if(a[n-1]<b[m-1]){
        for(auto x:a) sum+=x;
        for(int i=0;i<m-1;i++){
            if(sum>b[i]) res+=b[i];
            else res+=sum;
        }
        res+=sum;
    }else{
        for(auto x:b) sum+=x;
        for(int i=0;i<n-1;i++){
            if(sum>a[i]) res+=a[i];
            else res+=sum;
        }
        res+=sum;
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
