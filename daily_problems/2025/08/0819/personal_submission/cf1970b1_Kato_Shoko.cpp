#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e6 + 5, mod = 1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    int n;
    cin>>n;
    cout<<"YES\n";
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<i<<'\n';
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        cout<<(i+x/2<=n?i+x/2:i-x/2)<<" ";
    }
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
