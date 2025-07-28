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
    int n;
    std::cin>>n;
    std::vector<int> a(n+2),f(n+2);
    std::stack<int> q;
    for(int i=1;i<=n;i++) std::cin>>a[i];
    for(int i=1;i<=n;i++){
        int mx=0;
        while(q.size() and a[i]>a[q.top()]){
            mx=std::max(mx,f[q.top()]);
            q.pop();
        }
        if(q.size()) f[i]=mx+1;
        q.push(i); 
    }
    std::cout<<*max_element(all(f))<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
