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
    std::vector<int> a(n),la(n),ne(n);
    for(auto &x:a) std::cin>>x;
    for(int i=0;i<n;i++){
        la[i]=(i-1+n)%n;
        ne[i]=(i+1)%n;
    }
    std::queue<int> q;
    for(int i=0;i<n;i++) q.push(i);
    std::vector<int> res,st(n,0);
    while(q.size()){
        auto t=q.front();
        q.pop();
        if(st[t]) continue;
        if(std::gcd(a[t],a[ne[t]])==1){
            st[ne[t]]=1;
            res.pb(ne[t]+1);
            int l=t,r=ne[ne[t]];
            ne[l]=r;
            la[r]=l;
            q.push(t);
        }
    }
    std::cout<<res.size()<<" ";
    for(auto x:res) std::cout<<x<<" ";
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
