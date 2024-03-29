#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int MXN = 200005;
int p[MXN];
int p_pos[MXN];
int a[MXN];
constexpr int MX_LOG_N = 18;
int nxt[MX_LOG_N][MXN];
int seq_start_pos[MXN];

/* https://codeforces.com/problemset/submission/1142/253563475 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p_pos[p[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    map<int, int> last_pos;
    for (int i = 0; i < m; i++) {
        int aj = p[(p_pos[a[i]] + n - 1) % n];
        
        auto it = last_pos.find(aj);
        if (it != last_pos.end()) {
            nxt[0][i] = it->second;
        } else {
            nxt[0][i] = -1;
        }
        last_pos[a[i]] = i;
    }

    for (int k = 0; k + 1 <= MX_LOG_N; k++) {
        for (int i = 0; i < m; i++) {
            if (nxt[k][i] < 0) {
                nxt[k + 1][i] = -1;
            } else {
                nxt[k + 1][i] = nxt[k][nxt[k][i]];
            }
        }
    }

    for (int r = 0; r < m; r++) {
        int i = r;
        for (int k = MX_LOG_N; k >= 0 && i >= 0; k--) {
            if ((n - 1) & (1 << k)) {
                i = nxt[k][i];
            }
        }
        seq_start_pos[r] = r > 0 ? max(i, seq_start_pos[r - 1]) : i;
    }

    string ans(q, '0');
    for (int j = 0; j < q; j++) {
        int l, r;
        cin >> l >> r;
        if (seq_start_pos[r - 1] >= l - 1) {
            ans[j] = '1';
        }
    }

    cout << ans << "\n";

    return 0;
}

