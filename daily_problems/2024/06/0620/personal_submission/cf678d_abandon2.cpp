#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int md=1e9+7;

LL ksm(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1)res=res*a%md;
        a=a*a%md;
        b>>=1;
    }
    return res;
}

void solve(){
    LL a,b,x,n;
    cin>>a>>b>>n>>x;
    LL ans=ksm(a,n%(md-1))*x%md;
    //cout<<ans<<"\n";
    if(a==1){
        ans+=n%md*b;ans%=md;
    }
    else{
        ans+=b%md*(ksm(a,n%(md-1))-1+md)%md*ksm(a-1,md-2)%md;
        ans%=md;
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
