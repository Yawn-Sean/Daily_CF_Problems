#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n,q;cin >> n >> q;
    vector<vector<int>> phg(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> phg[i][j];

    vector<vector<int>> arr(2 * n - 1);
    int pos = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i-j+n - 1].push_back(phg[i][j]);
        }
    }
    // for (auto vec : arr) {
    //     for (auto i : vec) cout << i << ' ';
    //     cout << endl;
    // }
    while (q--) {
        int a, b;cin >> a >> b;
        int k = 0;
        for (auto &vec : arr) {
            auto st = lower_bound(vec.begin(), vec.end(), a);
            auto ed = upper_bound(vec.begin(), vec.end(), b);
            if (st!=vec.end()) {
                int nK = ed - st;
                if (nK > k) {
                    k = nK;
                }
            }
        }
        cout << k * k << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}