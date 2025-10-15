/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

std::vector<int> init_prime(int n){
    std::vector<int> prime,st(n+1,0);
    for(int i=2;i<=n;i++){
        if(!st[i]) prime.push_back(i),st[i]=i;
        for(int j=0;prime[j]*i<=n;j++){
            st[i*prime[j]]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
    return st;
}

constexpr int N=1e7+10;

void solve(){
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    auto mpr=init_prime(N);
    std::vector<int> res(n+2);

    std::vector<int> st(N);

    auto query=[&](int x)->bool{
        bool hv=0;
        while(x>1){
            int c=mpr[x];
            while(x%c==0) x/=c;
            if(st[c]) hv=1;
        }
        return hv;
    };

    auto push=[&](int i,int x){
        res[i]=x;
        while(x>1){
            int c=mpr[x];
            while(x%c==0) x/=c;
            st[c]=1;
        }
    };

    bool flag=0;

    for(int i=1,j=2;i<=n;i++){
        if(!flag){
            if(!query(a[i])) push(i,a[i]);
            else{
                int x=a[i]+1;
                while(query(x)) x++;
                push(i,x);
                flag=1;
            }
        }else{
            while(query(j)) j++;
            push(i,j);
        }
    }
    for(int i=1;i<=n;i++) std::cout<<res[i]<<" ";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
