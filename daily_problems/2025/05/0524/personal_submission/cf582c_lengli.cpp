/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=400010;
int a[N],g[N],f[N],cnt[N];

void solve(){
    int n;
    std::cin>>n;

    i64 res=0;

    for(int i=0;i<n;i++){
        std::cin>>a[i];
        a[i+n]=a[i];
    }
    for(int d=1;d<n;d++){
        if(n%d==0){
            std::bitset<N> st;
            for(int k=0;k<d;k++){
                g[k]=0;
                for(int i=k;i<(n<<1);i+=d){
                    g[k]=std::max(g[k],a[i]);
                }
                for(int i=k;i<(n<<1);i+=d){
                    if(a[i]==g[k]) st[i]=1;
                }
            }
            f[0]=st[0];
            for(int i=1;i<(n<<1);i++){
                if(st[i]) f[i]=f[i-1]+1;
                else f[i]=0;
                f[i]=std::min(f[i],n-1);
            }
            cnt[0]=0;
            for(int i=1;i<(n/d);i++){
                cnt[i]=cnt[i-1]+(std::gcd(i,n/d)==1);
            }
            for(int i=n;i<(n<<1);i++){
                res+=cnt[f[i]/d];
            }
        }
    }

    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
