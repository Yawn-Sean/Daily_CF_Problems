/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    std::priority_queue<int> q;
    std::map<int,int> st;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        st[a[i]]=1;
        q.push(a[i]);
    } 
    while(1){
        auto t=q.top();
        while(t>=1 and st[t]) t/=2;
        if(!t) break;
        auto v=q.top();
        q.pop();
        st[v]=0;
        st[t]=1;
        q.push(t);
    }
    while(q.size()){
        std::cout<<q.top()<<" ";
        q.pop();
    }

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
