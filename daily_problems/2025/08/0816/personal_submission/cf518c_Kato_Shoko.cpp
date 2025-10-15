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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n+1),pos(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    ll ans=0;
    while(m--){
        ll p;cin>>p;
        ll x=pos[p];
        ans+=(x-1)/k+1;
        if(x>1){
            ll y=x-1;
            swap(a[x],a[y]);
            swap(pos[a[x]],pos[a[y]]);
        }
    }
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
