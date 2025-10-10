#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e7 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    ll n,l,r;
    cin>>n>>l>>r;
    vector<ll>a(n);
    for(auto &i:a)cin>>i;
    ll k=min(n-r,l-1);
    while(k--){
        a.pop_back();
    }
    sort(a.rbegin(),a.rend());
    ll ans=0;
    for(int i=0;i<r-l+1;i++){
        ans+=a[i];
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
