/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

using i64=long long;

void solve(){
    i64 l,r;
    std::cin>>l>>r;

    auto cal=[&](i64 x)->i64{
        int m=0;
        for(int i=0;i<62;i++){
            if(x>>i&1) m=std::max(m,i+1);
        }
        std::vector<i64> f(m+2,0);
        for(int len=1;len<m;len++){
            for(int i=1;i<len;i++){
                if(len%i==0){
                    f[len/i]+=1<<(i-1);
                }
            }
        } 

        for(int i=1;i<m;i++){
            if(m%i==0){
                i64 k=0;
                for(int j=0;j<m;j+=i) k+=(1ll<<j);
                f[m/i]+=std::max(0ll,x/k-(1ll<<(i-1))+1);
            }
        }

        i64 res=0;
        for(int i=m;i>1;i--){
            for(int j=i*2ll;j<=m;j+=i) f[i]-=f[j];
            res+=f[i];
        }
        return res;
    };

    std::cout<<cal(r)-cal(l-1)<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
