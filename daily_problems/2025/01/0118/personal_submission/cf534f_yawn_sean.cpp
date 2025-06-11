#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divide, I conquer!

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> nums1(n), nums2(m);
    for (auto &v: nums1) cin >> v;
    for (auto &v: nums2) cin >> v;

    vector<vector<int>> msk_seps(n + 1);
    for (int i = 0; i < (1 << n); i ++) {
        int cnt = 0, cur = 0;
        for (int j = 0; j < n; j ++) {
            if (i >> j & 1) {
                if (cur == 0) cnt ++;
                cur = 1;
            }
            else cur = 0;
        }
        msk_seps[cnt].emplace_back(i);
    }

    vector<int> pw6(n + 1);
    pw6[0] = 1;
    for (int i = 1; i <= n; i ++)
        pw6[i] = pw6[i - 1] * 6;
    
    int total_msk = pw6[n] * (1 << n), total = 1 << n;
    int left = m / 2, right = m - m / 2;

    vector<vector<int>> dp_left(left + 1, vector<int>(total_msk, -2));
    dp_left[0][0] = -1;

    for (int i = 0; i < left; i ++) {
        for (int msk = 0; msk < total_msk; msk ++) {
            if (dp_left[i][msk] != -2) {
                int status = msk / total, border = msk % total;
                for (auto &nborder: msk_seps[nums2[i]]) {
                    int nstatus = status, new_pos = nborder - (border & nborder);
                    for (int j = 0; j < n; j ++) {
                        if (new_pos >> j & 1) {
                            nstatus += pw6[j];
                        }
                    }
                    dp_left[i + 1][nstatus * total + nborder] = msk;
                }
            }
        }
    }

    vector<vector<int>> dp_right(right + 1, vector<int>(total_msk, -2));
    dp_right[0][0] = -1;

    for (int i = 0; i < right; i ++) {
        for (int msk = 0; msk < total_msk; msk ++) {
            if (dp_right[i][msk] != -2) {
                int status = msk / total, border = msk % total;
                for (auto &nborder: msk_seps[nums2[m - 1 - i]]) {
                    int nstatus = status, new_pos = nborder - (border & nborder);
                    for (int j = 0; j < n; j ++) {
                        if (new_pos >> j & 1) {
                            nstatus += pw6[j];
                        }
                    }
                    dp_right[i + 1][nstatus * total + nborder] = msk;
                }
            }
        }
    }

    for (int msk1 = 0; msk1 < total_msk; msk1 ++) {
        if (dp_left[left][msk1] != -2) {
            int status1 = msk1 / total, border1 = msk1 % total, v = status1;
            vector<int> tmp;
            for (int i = 0; i < n; i ++) {
                tmp.emplace_back(v % 6);
                v /= 6;
            }
            for (int border2 = 0; border2 < (1 << n); border2 ++) {
                int share = border1 & border2, status2 = 0;
                bool flg = true;
                
                for (int i = 0; i < n; i ++) {
                    int target = nums1[i] - tmp[i];
                    if (share >> i & 1) target ++;
                    if (target < 0 || target >= 6) flg = false;
                    status2 += target * pw6[i];
                }
                if (!flg) continue;
                int msk2 = status2 * total + border2;

                if (msk2 < dp_right[0].size() && dp_right[right][msk2] != -2) {
                    vector<int> ans;
                    for (int i = left; i > 0; i --) {
                        ans.emplace_back(msk1 % total);
                        msk1 = dp_left[i][msk1];
                    }
                    reverse(ans.begin(), ans.end());
                    for (int i = right; i > 0; i --) {
                        ans.emplace_back(msk2 % total);
                        msk2 = dp_right[i][msk2];
                    }

                    for (int i = 0; i < n; i ++) {
                        for (int j = 0; j < m; j ++) {
                            cout << (ans[j] >> i & 1 ? '*' : '.');
                        }
                        cout << '\n';
                    }
                    return 0;
                }
            }
        }
    }

    return 0;
}