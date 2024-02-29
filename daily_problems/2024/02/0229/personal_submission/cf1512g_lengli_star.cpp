//令f(x)为x的因数和
//不难看出当x,y互质时，f(x*y)=f(x)*f(y)。(通过分解质因数即可证明)
//则f(x)为积性函数，故使用欧拉筛进行预处理即可。
//若x为质数f(x)=x+1。(只包含因子x与1)
//若gcd(x,prime[j])==1，f(x*prime[j])=f(prime[j])*f(x);
//若gcd(x,prime[j])!=1，则x*prime[j]共包含cnt+1个prime[j]的乘积，cnt为最大的满足(x%(prime[j]^cnt)==0)的正整数。
//那么gcd(x/prime[j],prime[j]^(cnt+1))==1,则f(x*prime[j])=f(x/prime[j])*f(prime[j]^(cnt+1));
/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=10000010;

int res[N];

void init(){
    vector<int> prime;
    vector<int> st(N+1,0),phi(N+1,0);
    phi[1]=1;
    for(int i=2;i<N;i++){
        if(!st[i]) st[i]=1,prime.pb(i),phi[i]=1+i;
        for(int j=0;prime[j]*i<N;j++){
            st[prime[j]*i]=1;
            if(i%prime[j]==0){
                int t=i*prime[j],k=1;
                while(t%prime[j]==0) t/=prime[j],k*=prime[j];
                int q=0;
                for(int ii=1;ii<=k/ii;ii++){
                    if(k%ii==0) {
                        q+=ii;
                        if(k/ii!=ii) q+=k/ii;
                    }
                }
                phi[i*prime[j]]=phi[t]*q;
                break;
            }else phi[i*prime[j]]=phi[i]*phi[prime[j]];
        }
    }
    memset(res,-1,sizeof res);
    for(int i=0;i<N;i++){
        if(phi[i]!=0 and phi[i]<N and res[phi[i]]==-1){
            res[phi[i]]=i;
        }

    }
}

void solve(){
    int x;
    cin>>x;
    cout<<res[x]<<endl;
}

signed main(){
    fastio;
    init();
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
