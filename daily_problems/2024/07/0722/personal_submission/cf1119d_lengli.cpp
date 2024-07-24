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
    int n;
    std::cin>>n;
    std::vector<int> a(n),b;
    for(auto &x:a) std::cin>>x;
    sort(all(a));
    a.erase(std::unique(all(a)),a.end());
    for(int i=1;i<a.size();i++) b.pb(a[i]-a[i-1]);
    sort(all(b));
    int m;
    std::cin>>m;
    std::vector<int> res(m);
    std::vector<std::array<int,2>> qr(m);
    for(int i=0;i<m;i++){
        int l,r;
        std::cin>>l>>r;
        qr[i]={r-l+1,i};
    }
    sort(all(qr));
    int ans=0,la=0,j=0;
    for(auto [len,id]:qr){
        ans+=(len-la)*a.size();
        ans-=(len-la)*j;
        while(j<b.size() and b[j]<len){
            ans-=(len-b[j]);
            j++;
        }
        la=len;
        res[id]=ans;
    }
    for(auto x:res) std::cout<<x<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
