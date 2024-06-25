#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

const int N = 26, inf = 0x3f3f3f3f;
int dist[N][N];

void solve() { 
    string a, b, ans; cin >> a >> b;
    if (a.size() != b.size()) return (void)(cout << "-1" << endl);
    int n; cin >> n;
    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i < N; i++) dist[i][i] = 0;
    for (int i = 0; i < n; i++) {
        string from, to;
        int t;
        cin >> from >> to >> t;
        dist[from[0] - 'a'][to[0] - 'a'] = min(dist[from[0] - 'a'][to[0] - 'a'], t);
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ll num = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) {
            ans.push_back(a[i]);
            continue;
        }
        int ind_a = a[i] - 'a', ind_b = b[i] - 'a';
        int val = INT_MAX, to = -1;
        for (int j = 0; j < 26; j++) {
            if (dist[ind_a][j] == inf || dist[ind_b][j] == inf) continue;
            if (dist[ind_a][j] + dist[ind_b][j] < val) val = dist[ind_a][j] + dist[ind_b][j], to = j;
        }
        if (to == -1) break;
        num += val;
        ans.push_back(to + 'a');
    }
    if (ans.size() != a.size()) cout << "-1" << endl;
    else cout << num << endl << ans << endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
