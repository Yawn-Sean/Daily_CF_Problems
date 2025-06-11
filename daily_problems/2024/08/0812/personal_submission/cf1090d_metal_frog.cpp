#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
 
void solve() {
    int n, m;
    cin >> n >> m;
    map<int, set<pii>> edge;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (a > b) swap(a, b);
        edge[b - a].insert({a, b});
    }
    int found = -1;
    pii point;
    for (int len = 1; len <= n - 1; len++) {
        if (edge[len].size() < n - len) {
            for (int i = 0; i < n - len; i++) {
                if (edge[len].find({i, i + len}) == edge[len].end()) {
                    found = len;
                    point = {i, i + len};
                    goto loopEnd;
                }
            }
        }
    }
loopEnd:
    if (found == -1 || n == 1) {
        cout << "NO\n";
        return;
    }
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[i] = b[i] = i + 1;
    }
    if (found == 1) {
        auto [i, j] = point;
        b[i] = b[j] = a[i];   
    } else {
        auto [i, j] = point;
        swap(a[i + 1], a[j]);
        swap(b[i + 1], b[j]);
        b[i] = b[j];
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
}
 
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
