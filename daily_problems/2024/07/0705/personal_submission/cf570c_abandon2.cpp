#include<bits/stdc++.h>
using namespace std;
const int N =3e5+10;
using LL=long long;
int l[N],r[N],a[N];

void solve(){
    int n,m;cin>>n>>m;
    string s;cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        a[i]=(s[i]=='.'?1:0);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=(a[i-1]&&a[i]);
    }

    for(int i=1;i<=m;i++){
        int p;char c;
        cin>>p>>c;
        int x=(c=='.'?1:0);
        if(a[p]!=x){
            if(x)ans+=(a[p-1]+a[p+1]);
            else ans-=(a[p-1]+a[p+1]);
        }
        a[p]=x;
        cout<<ans<<"\n";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
