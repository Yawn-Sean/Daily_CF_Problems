/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=10000010;

int la[N];

void init_prime(){
    std::vector<int> prime,st(N,0);
    for(int i=2;i<N;i++){
        if(!st[i]) prime.push_back(i),la[i]=i;
        for(int j=0;prime[j]*i<N;j++){
            st[i*prime[j]]=1;
            la[i*prime[j]]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
    return;
}

void solve(){
    init_prime();

    int n,m;
    std::cin>>n>>m;
    std::vector<int> a(n+2),b(m+2);
    std::map<int,int> q,p;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        int x=a[i];
        while(x>1){
            q[la[x]]++;
            x/=la[x];
        }
    }
    for(int i=1;i<=m;i++){
        std::cin>>b[i];
        int x=b[i];
        while(x>1){
            p[la[x]]++;
            x/=la[x];
        }
    }

    for(int i=1;i<=n;i++){
        int x=a[i];
        while(x>1){
            if(p[la[x]]){
                p[la[x]]--;
                a[i]/=la[x];
            }
            x/=la[x];
        }
    }
    for(int i=1;i<=m;i++){
        int x=b[i];
        while(x>1){
            if(q[la[x]]){
                q[la[x]]--;
                b[i]/=la[x];
            }
            x/=la[x];
        }
    }


    std::cout<<n<<" "<<m<<"\n";
    for(int i=1;i<=n;i++) std::cout<<a[i]<<" ";std::cout<<"\n";
    for(int i=1;i<=m;i++) std::cout<<b[i]<<" ";std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
