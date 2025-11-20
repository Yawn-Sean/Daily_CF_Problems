/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

int LIS_len(std::vector <int> a){
    std::vector<int> q;
    for(auto x:a){
        auto it=std::lower_bound(q.begin(),q.end(),x);
        if(it==q.end()){
            q.push_back(x);
        }else{
            *it=x;
        }
    }
    return (int)q.size();
}

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2),b(n+2),q;
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=n;i++) std::cin>>b[i];
    for(int i=1;i<=n;i++){
        if(a[i]>b[i]) q.pb(a[i]),q.pb(b[i]);
        else q.pb(b[i]),q.pb(a[i]);
    }
    std::cout<<LIS_len(q)<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
