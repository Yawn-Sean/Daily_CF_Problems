/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

int mi[10000010],cnt[10000010];

void sieve(int n){
    std::vector<int> prime,st(n+2);
    for(int i=2;i<=n;i++){
        if(!st[i]) prime.pb(i),mi[i]=i;
        for(int j=0;prime[j]*i<=n;j++){
            st[prime[j]*i]=1;
            mi[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
}

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }

    sieve(10000000);

    int d=std::gcd(a[1],a[2]);
    for(int i=1;i<=n;i++){
        if(a[i]%d){
            std::cout<<"NO"<<"\n";
            return;
        }
        a[i]/=d;
    }

    bool flag=1;

    for(int i=1;i<=n and flag;i++){
        while(a[i]>1 and flag){
            int v=mi[a[i]];
            while(a[i]%v==0) a[i]/=v;
            cnt[v]++;
            if(cnt[v]>=2){
                flag=0;
            }
        }
    }

    std::cout<<(flag ? "YES" : "NO")<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
