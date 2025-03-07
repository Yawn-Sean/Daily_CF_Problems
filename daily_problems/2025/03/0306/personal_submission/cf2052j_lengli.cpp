/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int inf=1e9;

void solve(){
    int n,m,q;
    std::cin>>n>>m>>q;
    std::vector<std::array<int,2>> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i][0];
    for(int i=1;i<=n;i++) std::cin>>a[i][1];

    std::vector<int> b(m+2),c(m+2);
    for(int i=1;i<=m;i++) std::cin>>b[i];
    sort(a.begin()+1,a.end()-1,[&](auto l,auto r){
        return l[1]<r[1];
    });

    int t=0,i=1,j=1;
    while(i<=n){
        while(j>0 and t+a[i][0]>a[i][1]){
            j--;
            t-=b[j];
            c[j]=inf;
        }
        while(j<=m and t+b[j]<=a[i][1]-a[i][0]){
            t+=b[j];
            c[j]=t;
            j++;
        }
        t+=a[i][0];
        i++;
    }

    while(j<=m){
        t+=b[j];
        c[j]=t;
        j++;
    }
    while(q--){
        int x;
        std::cin>>x;
        std::cout<<std::upper_bound(c.begin()+1,c.begin()+m+1,x)-c.begin()-1<<" ";
    }
    std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
