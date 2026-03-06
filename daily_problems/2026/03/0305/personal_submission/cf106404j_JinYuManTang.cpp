//  J. Balancing
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr i64 inf = 1E18;
constexpr int MOD = 1'000'000'007;

template<class T>
bool chmax(T &a, T b) {
    if (a >= b) return false;
    a = b;
    return true;
}

template<class T>
bool chmin(T &a, T b) {
    if (a <= b) return false;
    a = b;
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &row : a) {
        for (auto &x: row) {
            cin >> x;
        }
    }
    vector<vector<int>> s(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) {
                s[i + 1][j + 1] = 1;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            s[i][j + 1] += s[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            s[i + 1][j] += s[i][j];
        }
    }

    vector<vector<int>> nxt(n, vector<int>(m + 1, m));
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            nxt[i][j] = nxt[i][j + 1];
            if (a[i][j]) {
                nxt[i][j] = j;
            }
        }
    }

    auto has = [&](int x1, int y1, int x2, int y2) {
        return s[x1][y1] - s[x1][y2 + 1] - s[x2 + 1][y1] + s[x2 + 1][y2 + 1];
    };

    int q;
    cin >> q;
    int N = 30;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        vector<int> chosen;
        int i = x1;
        while (chosen.size() <= N) {
            int left = i - 1, right = x2 + 1;
            while (left + 1 < right) {
                int mid = (left + right) / 2;
                if (has(i, y1, mid, y2)) {
                    right = mid;
                } else {
                    left = mid;
                }

            }
            if (right == x2 + 1) {
                break;
            }
            for (int j = y1; nxt[right][j] <= y2; j++) {
                j = nxt[right][j];
                chosen.push_back(a[right][j]);
                if (chosen.size() > N) {
                    break;
                }
            }
            i = right + 1;
        }

        if (chosen.size() > N) {
            cout << "YES\n";
        } else {
            sort(chosen.begin(), chosen.end());
            bool ok = false;
            for (int i = 2; i < chosen.size(); i++) {
                if (chosen[i - 2] + chosen[i - 1] > chosen[i]) {
                    ok = true;
                    break;
                }
            }
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
