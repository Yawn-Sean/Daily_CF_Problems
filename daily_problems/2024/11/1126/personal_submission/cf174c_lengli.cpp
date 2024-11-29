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
    std::vector<int> a(n+2),b(n+2);
    std::vector<int> p,q;
    for(int i=1;i<=n+1;i++){
        if(i<=n) std::cin>>a[i];
        b[i]=a[i]-a[i-1];
        int cnt=std::abs(b[i]);
        if(b[i]>0){
            while(cnt--) q.pb(i);
        }else {
            while(cnt--) p.pb(i);
        }
    }

    std::cout<<q.size()<<"\n";
    for(int i=0;i<q.size();i++){
        if(i<p.size()) std::cout<<q[i]<<" "<<p[i]-1<<"\n";
        else std::cout<<q[i]<<" "<<q[i]<<"\n";
    }
    
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
