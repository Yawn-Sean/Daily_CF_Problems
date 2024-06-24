#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod=1e9+7;

LL qpow(LL a,LL b)
{
    LL res=1;
    while(b)
    {
        if(b&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

int main()
{
    LL a,b,n,x;
    cin>>a>>b>>n>>x;
    if(a==1)
    {
        LL res=(x%mod+n%mod*b%mod)%mod;
        cout<<res<<'\n';
    }
    else
    {
        LL res1=qpow(a,n)*x%mod;
        LL res2=((qpow(a,n)-1)*(qpow(a-1,mod-2))%mod*b)%mod;
        LL res=(res1+res2)%mod;
        cout<<res<<'\n';
    }
    return 0;
}
