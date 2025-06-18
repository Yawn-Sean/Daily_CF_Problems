/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

template<typename T>
struct two_dimensional_presum{//idx:1~n
    int n,m;
    std::vector<std::vector<T>> b;
    two_dimensional_presum(){};
    two_dimensional_presum(int n,int m,std::vector<std::vector<T>> a){
        b.swap(a);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) b[i][j]+=b[i][j-1];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) b[i][j]+=b[i-1][j];
    };
    T query(int x_1,int y_1,int x_2,int y_2){
        return b[x_2][y_2]-b[x_1-1][y_2]-b[x_2][y_1-1]+b[x_1-1][y_1-1];
    };
};

void solve(){
    int n,q;
    std::cin>>n>>q;
    std::vector<std::vector<i64>> a(n+2,std::vector<i64> (n+2,0));
    std::vector<std::vector<i64>> ia(n+2,std::vector<i64> (n+2,0));
    std::vector<std::vector<i64>> ja(n+2,std::vector<i64> (n+2,0));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            std::cin>>a[i][j];
            ia[i][j]=a[i][j]*i;
            ja[i][j]=a[i][j]*j;
        }
    
    two_dimensional_presum<i64> A(n,n,a);
    two_dimensional_presum<i64> iA(n,n,ia);
    two_dimensional_presum<i64> jA(n,n,ja);

    while(q--){
        int x,y,a,b;
        std::cin>>x>>y>>a>>b;
        i64 res=0;
        res+=A.query(x,y,a,b)*(1-x*(b-y+1)-y);
        res+=iA.query(x,y,a,b)*(b-y+1);
        res+=jA.query(x,y,a,b);
        std::cout<<res<<" ";
    }std::cout<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
