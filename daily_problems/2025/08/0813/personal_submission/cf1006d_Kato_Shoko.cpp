#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-3;
double PI=3.1415926;

il void solve(){
    int n;
    string a,b;
    cin>>n>>a>>b;
    a="!"+a,b="!"+b;
    ll ans=0;
    for(int i=1;i<=n/2;i++){
        char x,y,z,q;
        x=a[i],y=a[n-i+1],z=b[i],q=b[n-i+1];
        if((x==y&&z==q)||(x==z&&y==q)||(x==q&&y==z)){

        }else if(x==z||x==q||y==z||y==q||z==q){
            ans++;
        }else{
            ans+=2;
        }
    }
    if(n&1)ans+=a[(n+1)>>1]!=b[(n+1)>>1];
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    //cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
