#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    map<int, int> ncnt;
    map<int, int> n_ncnt;
    
    int mxpos = -1;

    for (int i = 0; i < n; i++) {
        int elm = a[i];
        int pre_v = ncnt[elm];
        int curv = pre_v + 1;
        ncnt[elm] = curv;

        if (pre_v) {
            n_ncnt[pre_v] --;
            if (n_ncnt[pre_v] == 0) {
                n_ncnt.erase(pre_v);
            }
        }
        n_ncnt[curv] ++;

        if (n_ncnt.size() == 1) {
            auto [cnt_val, cnt_cnt] = *n_ncnt.begin();
            if (cnt_val == 1 || cnt_cnt == 1) {
                mxpos = max(mxpos, i);
            }
        } else if (n_ncnt.size() == 2) {
            auto [f_cnt_val, f_cnt_cnt] = *n_ncnt.begin();
            auto [b_cnt_val, b_cnt_cnt] = *n_ncnt.rbegin();
            if ((f_cnt_cnt == 1 && f_cnt_val == 1) || (b_cnt_val == f_cnt_val + 1 && b_cnt_cnt == 1)) {
                mxpos = max(mxpos, i);
            }
        }
    }
    
    cout << mxpos + 1 << "\n";
}

int main(void) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T{1};
    // cin >> T;
    while (T--) {
        solve();
    }

}