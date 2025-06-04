/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr i64 inf=1e15;

i64 qmi(i64 a,i64 b){
    i64 res=1;
    for(int i=1;i<=b;i++){
        res*=a;
        if(res>=inf) return res;
    }
    return res;
}

void solve(){
    int a,b,n;
    std::cin>>a>>b>>n;
    if(a==1 and qmi(2,b)>=n){
        std::cout<<"Missing"<<"\n";
        return;
    }

    if(b==1 and 1ll*a*a>=n){
        if(a>=n) std::cout<<"Stas"<<"\n";
        else if((a-n)%2==0) std::cout<<"Masha"<<"\n";
        else std::cout<<"Stas"<<"\n";
        return;
    }

    std::vector<std::vector<int>> f(100002,std::vector<int> (50,-1));

    auto dfs=[&](auto self,int l,int r)->int{
        if(qmi(l,r)>=n or (qmi(l+1,r)>=n and qmi(l,r+1)>=n)){
            return f[l][r]=0;
        }

        if(r==1 and 1ll*l*l>=n){
            if(l>=n) return f[l][r]=0;
            else if((l-n)%2==0) return f[l][r]=1;
            else return f[l][r]=0;
        }

        if(f[l][r]!=-1) return f[l][r];
        int flag=0;
        if(qmi(l+1,r)<n and !self(self,l+1,r)) flag=1;
        if(qmi(l,r+1)<n and !self(self,l,r+1)) flag=1;
        return f[l][r]=flag;
    };

    dfs(dfs,a,b);

    std::cout<<(f[a][b]==1 ? "Masha" : "Stas")<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
