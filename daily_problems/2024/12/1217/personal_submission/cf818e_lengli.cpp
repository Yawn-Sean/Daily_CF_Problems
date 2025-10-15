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
    std::vector<std::array<int,2>> fac;
    for(int i=2;1ll*i*i<=k;i++){
        if(k%i) continue;
        int v=i,cnt=0;
        while(k%i==0){
            k/=i;
            cnt++;
        }
        fac.pb({v,cnt});
    }
    if(k>1) fac.pb({k,1});

    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];

    int m=fac.size();
    std::vector<std::vector<int>> f(m,std::vector<int> (n+2,0));
    for(int i=0;i<m;i++){
        auto [x,_]=fac[i];
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(a[j]%x) {
                f[i][j]=cnt;
                continue;
            }
            int v=a[j];
            while(v%x==0){
                v/=x;
                cnt++;
            }
            f[i][j]=cnt;
        }
    }


    i64 res=0;

    for(int i=1;i<=n;i++){
        int mx=i;
        bool flag=1;
        for(int ii=0;ii<m;ii++){
            auto [x,cnt]=fac[ii];
            auto check=[&](int idx)->bool{
                return f[ii][idx]-f[ii][i-1]>=cnt;
            };

            int l=i,r=n;
            while(l<r){
                int mid=(l+r)/2;
                if(check(mid)) r=mid;
                else l=mid+1;
            }
            if(check(r)) mx=std::max(mx,r);
            else flag=0;
        }
        if(flag) res+=n-mx+1;
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
