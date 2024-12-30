#include<bits/stdc++.h>
using namespace std;
const int N=5010,md= 998244353;
typedef long long LL;
LL fac[N],inv[N];

LL ksm(LL a,LL b){  
    LL res=1;  
    while(b){  
        if(b&1)res=res*a%md;  
        b>>=1;  
        a=a*a%md;  
    }  
    return res;  
}  
  
void init(){  
    int n=5e3+5;  
    fac[0]=1;  
    for(int i=1;i<=n;i++)  
        fac[i]=fac[i-1]*i%md;  
    inv[n]=ksm(fac[n],md-2);  
    for(int i=n;i>=1;i--)  
        inv[i-1]=inv[i]*i%md;  
}  
  
LL C(int n,int m){  
    if(m>n)return 0;  
    if(m==0)return 1;  
    return fac[n]*inv[m]%md*inv[n-m]%md;  
}

LL A(int n,int m){
    return fac[n]*inv[n-m]%md;
}

void solve(){
    int a,b,c;cin>>a>>b>>c;
    auto clac=[&](int a,int b){
        if(a>b)swap(a,b);
        LL ans=0;
        for(int i=0;i<=a;i++){
            ans+=A(a,i)*C(b,i)%md;
            ans%=md;
        }   
        return ans;
    };  
    LL ans=0;
    ans=(clac(a,b)*clac(a,c))%md*clac(b,c)%md;
    cout<<ans%md<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}
