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
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    int mx=0;
    int mid=(n%2==1 ? n/2+1 : n/2);
    std::map<int,int> q;
    for(int i=1;i<=mid;i++){
        int v=a[i]+1-i;
        if(v>0) {
            q[v]++;
            mx=std::max(q[v],mx);
        }
    }
    for(int i=mid+1;i<=n;i++){
        int v=a[i]+i-n;
        if(v>0) {
            q[v]++;
            mx=std::max(q[v],mx);
        }
    }

    std::cout<<n-mx<<"\n";
}

signed main(){
    fastio;

    int T;
    T=1;
    while(T--) solve();

    return 0;
}
