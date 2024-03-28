#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> p(n);
    copy_n(istream_iterator<int>(cin), n, begin(p));
    vector<int> a(m);
    copy_n(istream_iterator<int>(cin), m, begin(a));

    vector<int> val2Idx_n(n + 1, -1);
    for (int i = 0; i < n; ++i) {
        val2Idx_n[p[i]] = i;
    }
    vector<int> idxm2Idxn(m, -1);
    for (int i = 0; i < m; ++i) {
        idxm2Idxn[i] = val2Idx_n[a[i]];
    }

    int k = __lg(n);
    vector<vector<int>> st(m + 1, vector<int>(k + 1, m));
    vector<int> next(n, m);
    for (int i = m - 1; i >= 0; --i) {
        st[i][0] = next[(idxm2Idxn[i] + 1) % n];
        next[idxm2Idxn[i]] = i;
    }

    for (int j = 1; j <= k; ++j) {
        for (int i = 0; i < m; ++i) {
            st[i][j] = st[st[i][j - 1]][j - 1];
        }
    }

    vector<int> end_pos(m + 1);
    iota(begin(end_pos), end(end_pos), 0);
    for (int i = m - 1; i >= 0; --i) {
        for (int j = 0; j <= k; ++j) {
            if ((n - 1) >> j & 1) {
                end_pos[i] = st[end_pos[i]][j];
            }
        }
        end_pos[i] = min(end_pos[i], end_pos[i + 1]);
    }
    
    string ret;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        ret += end_pos[l] <= r ? "1" : "0";
    }

    cout << ret << '\n';
    return 0;
}