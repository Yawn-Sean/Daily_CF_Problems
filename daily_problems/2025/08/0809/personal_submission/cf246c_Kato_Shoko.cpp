#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e6 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-3;
double PI=3.1415926;

il void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=1;i<=n&&k;i++){
        for(int j=i;j<=n&&k;j++){
            cout<<i;
            //包含前(i-1)个最大元素
            //再加上元素a[n-j] 
            for(int t=1;t<i;t++){
                cout<<" "<<a[n-t];
            }
            cout<<" "<<a[n-j]<<'\n';
            k--;
        }
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
