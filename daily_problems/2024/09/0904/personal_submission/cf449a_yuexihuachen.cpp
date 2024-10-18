#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int, int> pii;
const int N = 5e5 + 10;
int n,m,k;

void solve() {
    cin >> n >> m >> k;
    if(k > (n+m-2)) { //n*m的巧克力最多切n+m-2刀
        cout << -1 << endl;
        return;
    }
    if(k < n && k < m){
        int ans = max(m*(n/(k+1)), n*(m/(k+1)));
        cout << ans << endl;
        return;
    }
    if(k < m && k >= n){
        int ans = max(n*(m/(k+1)), m/(k-n+2));
        cout << ans << endl;
        return;
    }
    if(k >= m && k < n){
        int ans = max(m*(n/(k+1)), n/(k-m+2));
        cout << ans << endl;
        return;
    }
    cout << max(n/(k-m+2), m/(k-n+2)) << endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    //  cin >> T;
    while (T--)
        solve();
    return 0;
}
