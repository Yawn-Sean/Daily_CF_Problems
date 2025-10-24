#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    int cnt = 0;
    for (auto s : g) {
        for (char c : s) cnt += (c == '#');
    }

    vector<vector<int>> g1(n + 1000, vector<int>(m + 1000, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            g1[i][j] = (g[i][j] == '#');
        }
    }

    for (int l = min(n, m); l >= 1; l--) {
        if (cnt % (l * l) == 0) {
            vector<vector<int>> tmp = g1;
            int ok = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (tmp[i][j] == 1) {
                        for (int x = i; x < i + l; x++) {
                            for (int y = j; y < j + l; y++) {
                                if (tmp[x][y] != 1) {
                                    ok = false;
                                    break;
                                }
                                tmp[x][y] = 0;
                            }
                            if (!ok) break;
                        }
                    }
                    if (!ok) break;
                }
                if (!ok) break;
            }

            if (ok) {
                cout << l << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
