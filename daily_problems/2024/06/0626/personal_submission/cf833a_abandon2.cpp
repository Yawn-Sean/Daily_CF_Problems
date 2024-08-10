#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve(){
    LL a,b;cin>>a>>b;
    LL x=a*b;
    LL p=round(pow(x,1.0/3));
    if(p*p*p==x&&a%p==0&&b%p==0){
        cout<<"Yes\n";return;
    }
    else{
        cout<<"No\n";
    }



}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;cin>>tt;
    while(tt--)
        solve();
    return 0;
}

