#include <bits/stdc++.h>
using namespace std;

void work() {
    int n, m; cin >> n >> m;

    vector<vector<int>> mmp(n);
    while (m --) {
        int s, t; cin >> s >> t;
        s --; t --;
        mmp[s].push_back(t);
        mmp[t].push_back(s);
    }

    vector<pair<int, int>> lns;

    function<bool(int)> bf_circle = [&] (int cur) {
        vector<int> fa(n, -1);
        vector<int> gp(n, -1);

        fa[cur] = cur;
        queue<int> elms;
        for (auto elm : mmp[cur]) {
            fa[elm] = cur;
            gp[elm] = elm;
            elms.push(elm);
        }

        while (!elms.empty()) {
            int f = elms.front();
            elms.pop();
            for (auto elm : mmp[f]) {
                if (fa[elm] != -1) continue;
                fa[elm] = f;
                gp[elm] = gp[f];
                elms.push(elm);
            }
        }

        for (int sp = 0; sp < n; sp ++) {
            if (sp == cur || gp[sp] == -1) continue;
            for (auto ep : mmp[sp]) {
                if (ep == cur || gp[ep] == -1) continue;
                if (gp[sp] != gp[ep]) {
                    lns.emplace_back(sp, ep);
                    while (sp != cur) {
                        lns.emplace_back(sp, fa[sp]);
                        gp[sp] = -1;
                        sp = fa[sp];
                    }
                    while (ep != cur) {
                        lns.emplace_back(ep, fa[ep]);
                        gp[ep] = -1;
                        ep = fa[ep];
                    }
                    for (int t = 0; t < 2; t ++) {
                        for (auto elm : mmp[cur]) {
                            if (gp[elm] != -1) {
                                gp[elm] = -1;
                                lns.emplace_back(elm, cur);
                                break;
                            }
                        }
                    }
                    return true;
                }
            }
        }
        return false;
    };

    for (int i = 0; i < n; i ++) {
        if (mmp[i].size() >= 4 && bf_circle(i)) {
            break;
        }
    }

    if (lns.size()) {
        cout << "YES\n";
        cout << lns.size() << "\n";
        for (auto elm : lns) {
            cout << elm.first + 1 << " " << elm.second + 1 << "\n";
        }
    } else {
        cout << "NO\n";
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