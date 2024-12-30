/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

const int N=100010;

struct BIT{
    int n=N-1;
    int a[N];
    int lowbit(int x){return x&-x;}
    void add(int x,int c) {for(int i=x;i<=n;i+=lowbit(i)) a[i]+=c;}
    int sum(int x){
        int res=0;
        for(int i=x;i;i-=lowbit(i)) res+=a[i];
        return res;
    }
}tr[12];

void solve(){
    int n,k;
    std::cin>>n>>k;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::vector<std::vector<int>> f(n+2,std::vector<int>(k+2,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k+1;j++){
            if(j==1) f[i][j]=1;
            else{
                f[i][j]+=tr[j-1].sum(a[i]-1);
            }
            tr[j].add(a[i],f[i][j]);
        }
    }

    std::cout<<tr[k+1].sum(N-1);
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
