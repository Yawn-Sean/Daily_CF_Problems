#include <bits/stdc++.h>
using namespace std;

void work() {
    int n; cin >> n;
    int m; cin >> m;


    vector<int> deg(n);
    vector<vector<int>> mmp(n, vector<int>(n, 0));
    vector<int> ans(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u --;
        v --;
        mmp[u][v] = mmp[v][u] = 1;
        deg[u] ++; 
        deg[v] ++;
    }

    // 1. scan, calc deg[i]   ==>   「deg[i] = n - 1 => b」
    int bcnt = 0;
    for (int i = 0 ; i < n; i++) {
        if (deg[i] == n - 1) {
            ans[i] = 2;
            bcnt ++;
            for (int j = 0; j < n; j++) {
                mmp[i][j] = mmp[j][i] = 0;
            }
        }
    }

    auto build = [&](int bv){
        int rtn = 0;
        for (int i = 0; i < n; i++) {
            if (ans[i] == 0) {
                int cur_p = i;
                while (cur_p != -1) {
                    ans[cur_p] = bv;
                    rtn ++;
                    int new_p = -1;
                    for (int j = 0; j < n; j++) {
                        if (mmp[cur_p][j] && ans[j] == 0) {
                            new_p = j;
                            break;
                        }
                    }
                    cur_p = new_p;
                }
                break;
            }
        }
        return rtn;
    };

    int acnt = build(1);
    int ccnt = build(3);

    bool bad = false;
    if (acnt + bcnt + ccnt != n) {
        bad = true;
    }

    for (int i = 0; i < n && !bad; i++) {
        if (ans[i] == 1 && (deg[i] - bcnt) != (acnt - 1)) {
            bad = true;
        } else if (ans[i] == 3 && (deg[i] - bcnt) != (ccnt - 1)) {
            bad = true;
        }
    }

    if (bad) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << static_cast<char>(ans[i] - 1 + 'a');
    }
    cout << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}