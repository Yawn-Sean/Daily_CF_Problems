/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

void solve(){
    int n,q;
    std::cin>>n>>q;
    std::vector<int> a(n),b(n);
    for(auto &x:a) std::cin>>x;
    std::sort(all(a));
    b[0]=a[0];
    for(int i=1;i<n;i++) b[i]=a[i]+b[i-1];
    std::set<int> s;

    std::function<void(int,int)> dfs=[&](int l,int r){
        if(l>r) return;

        if(l==r){
            s.insert(a[l]);
            return;
        }
        s.insert(b[r]-(l>0 ? b[l-1] : 0));
        int v=(a[l]+a[r])/2;

        auto find=[&](){
            int ll=l,rr=r;
            while(ll<rr){
                int m=(ll+rr+1)>>1;
                if(a[m]<=v) ll=m;
                else rr=m-1;
            }
            return ll;
        };
        int mid=find();
        if(mid==r) return;
        dfs(l,mid);
        dfs(mid+1,r);
    };

    dfs(0,n-1);

    while(q--){
        int x;
        std::cin>>x;
        std::cout<<(s.count(x) ? "Yes" : "No")<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
