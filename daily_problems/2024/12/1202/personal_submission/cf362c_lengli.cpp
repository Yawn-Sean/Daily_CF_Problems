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
    int n;
    std::cin>>n;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];
    std::vector<std::vector<int>> up(n+2,std::vector<int> (n+2));
    std::vector<std::vector<int>> down(n+2,std::vector<int> (n+2));
    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++) if(a[j]>i) up[i][j]=1;
        for(int j=1;j<=n;j++) if(a[j]<i) down[i][j]=1;
        for(int j=1;j<=n;j++){
            up[i][j]+=up[i][j-1];
            down[i][j]+=down[i][j-1];
        }
    }

    i64 inv=0;
    i64 ans=0,res=0;

    for(int i=1;i<=n;i++){
        int v=a[i];
        inv+=down[v][n]-down[v][i];
    }

    ans=inv;

    auto query=[&](std::vector<std::vector<int>> &q,int v,int l,int r){
        return q[v][r]-q[v][l];
    };

    auto check=[&](int i,int j)->i64{
        i64 tmp=inv;
        tmp-=query(down,a[i],i,j);
        tmp+=query(up,a[i],i,j);
        tmp-=query(up,a[j],i,j);
        tmp+=query(down,a[j],i,j);
        return tmp;
    };

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            i64 val=check(i,j);
            if(val<ans){
                ans=val;
                res=1;
            }else if(val==ans){
                res++;
            }

        }
    }
    
    std::cout<<ans<<" "<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
