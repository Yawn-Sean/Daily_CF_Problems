#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,l,m;
struct mtx {
    int c[4][4];
    mtx(){memset(c,0,sizeof c);}
}A,res;

mtx operator*(mtx &x,mtx &y){
    mtx t;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++)
            for(int k=1;k<=2;k++){
                t.c[i][j]=(t.c[i][j]+x.c[i][k]*y.c[k][j])%m;
            }
    }
    return t;
}

void ksm(int k){
    A.c[1][1]=A.c[1][2]=A.c[2][1]=1;
    A.c[2][2]=0;
    res.c[1][1]=res.c[2][1]=1;
    while(k){
        if(k&1)res=res*A;
        A=A*A;
        k>>=1;
    }

}

int p(int a){
    if(!a)return 1;
    int t=p(a>>1);
    if(a&1){
        return t*t*2%m;
    }
    return t*t%m;
}

void solve(){
    cin>>n>>k>>l>>m;
    ksm(n+1);
    int z0=res.c[1][1];

    int r=1%m;
    //cout<<p(n)<<"\n";
    int z1=(p(n)-z0+m)%m;
    //cout<<z0<<" "<<z1<<"\n";
    for(int i=l-1;i>=0;i--){
        if(k>>i&1)r=r*z1%m;
        else r=r*z0%m;
    }
    if(l<=63&&k>>l){
        r=0;
    }
    cout<<r<<"\n";
   // cout<<res.c[1][1]<<"\n";
}   

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
