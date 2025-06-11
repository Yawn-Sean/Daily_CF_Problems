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
    int n,k;
    std::cin>>n>>k;
    std::vector<int> a(k),st(n+2);
    std::stack<int> stk;
    int idx=1;
    for(int i=0;i<k;i++) {
        std::cin>>a[i];
        st[a[i]]=1;
        stk.push(a[i]);
        while(stk.size() and stk.top()==idx){
            idx++;
            stk.pop();
        }
    }
    while(stk.size()){
        int v=stk.top();
        for(int i=v-1;i>=idx;i--){
            if(st[i]){
                std::cout<<"-1"<<"\n";
                return;
            }
            a.pb(i);
            st[i]=1;
        }
        idx=v+1;
        stk.pop();
    }
    for(int i=n;i>=idx;i--) a.pb(i);
    for(auto x:a) std::cout<<x<<" ";std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
