#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n;
    string s, t;
    bool flag = true;
    cin >> n >> s >> t;
    vector<PII> ans;

    function<void(int, int)> op = [&](int i, int j) {
        swap(s[i], t[j]);
        ans.emplace_back(i + 1, j + 1);
    };

    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i]) {
            continue;
        }
        bool mid = false;
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j]) {
                op(j, i);
                mid = true;
                break;
            }
        }
        if (not mid) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == t[j]) {
                    op(i + 1, j);
                    op(i + 1, i);
                    mid = true;
                    break;
                }
            }
        }
        if (not mid) {
            flag = false;
        }
    }
    if (flag) {
        cout << "Yes" << endl << ans.size() << endl;
        for (auto [x, y] : ans) {
            cout << x << " " << y << endl;
        }
    } else {
        cout << "No" << endl;
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}
