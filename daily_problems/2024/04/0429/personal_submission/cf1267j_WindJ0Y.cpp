#include <bits/stdc++.h>
using namespace std;

void work() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i ++) {
        int t ;
        cin >> t;
        a[t] ++;
    } 

    vector<int> vals;
    int mxsize = 0;
    for (int i = 1; i <= n; i++) {
        int v = a[i];
        if (!v) {
            continue;
        }
        vals.emplace_back(v);
        mxsize = max(mxsize, v);
    }

    for (int psize = mxsize + 1; psize > 1; psize --) {
        int tans = 0;
        for (auto total : vals) {
            int pcnt = (total - 1) / psize + 1;
            if (pcnt * (psize - 1) <= total && pcnt * psize >= total) {
                tans += pcnt;
            } else {
                tans = -1;
                break;
            }
        }
        if (tans != -1) {
            cout << tans << '\n';
            return;
        }
    }

}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    cin >> T;

    while (T--) {
        work();
    }
}