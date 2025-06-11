#include<bits/stdc++.h>
using namespace std;
const int N =1e6+10,md=998244353;
typedef long long LL;
LL a[N];

LL ksm(LL a,LL b){
    LL res=1;
    int f=(b<0?1:0);
    b=abs(b);
    while(b){
        if(b&1)res=res*a%md;
        b>>=1;
        a=a*a%md;
    }
    return (f?ksm(res,md-2):res);
}

void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL ans=0;

    //cout<<ksm(2,-1)<<"\n";
    //cout<<ksm(2,md-2)<<"\n";
    for(int i=1;i<=n;i++){
        ans+=(n-i+2)*ksm(2,n-i-1)%md*a[i]%md;
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
