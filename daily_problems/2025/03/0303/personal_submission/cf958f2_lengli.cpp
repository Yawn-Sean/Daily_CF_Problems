/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=2e9;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<int> a(n+2),b(m+2);
    std::vector<int> c(n+2);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        c[a[i]]++;
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
        std::cin>>b[i];
        cnt+=(!b[i]);
    }
    std::fill(all(c),0);
    int res=inf,sum=0;
    for(int l=1,r=0;l<=n;l++){
        while(r<n and cnt<m){
            r++;
            c[a[r]]++;
            if(c[a[r]]==b[a[r]]) cnt++;
            if(c[a[r]]>b[a[r]]) sum++;
        }
        if(cnt==m) res=std::min(res,sum);
        else break;
        if(c[a[l]]>b[a[l]]) sum--;
        c[a[l]]--;
        if(c[a[l]]<b[a[l]]) cnt--;
    }
    std::cout<<(res==inf ? -1 : res)<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
