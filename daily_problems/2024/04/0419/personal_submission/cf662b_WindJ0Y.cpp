#include <bits/stdc++.h>
using namespace std;

void work() {
    int n, m; cin >> n >> m;

    vector<vector<pair<int, int>>> mmp(n);
    while (m--) {
        int s, t; cin >> s >> t; 
        s --;
        t --;
        string c; cin >> c;
        int cv = (c == "R" ? 0 : 1);
        mmp[s].emplace_back(t, cv);
        mmp[t].emplace_back(s, cv);
    }

    int opcnt_v = 1e9;
    vector<int> ansoplist;

    for (int target_c = 0 ; target_c < 2 ; target_c ++) {
        vector<int> opcnt(n, -1);
        vector<int> picked{};

        function<bool(int, int, vector<int>&, vector<int>&)> dfmark;
        dfmark = [&](int pid, int curop, vector<int> &la, vector<int> &lb){
            if (opcnt[pid] != -1) {
                return opcnt[pid] == curop;
            }
            opcnt[pid] = curop;
            vector<int> &target = (curop == 0 ? la : lb);
            target.emplace_back(pid);
            for (auto [npid, cv] : mmp[pid]) {
                if (!dfmark(npid, curop ^ cv ^ target_c, la, lb)) {
                    return false;
                }
            }
            return true;
        };

        bool bad = false;
        for (int i = 0; i < n ; i ++) {
            if (opcnt[i] == -1) {
                vector<int> la, lb;
                bool suc = dfmark(i, 0, la, lb);
                if (!suc) {
                    bad = true;
                    break;
                }
                if(la.size() < lb.size()) {
                    picked.insert(picked.end(), la.begin(), la.end());
                } else {
                    picked.insert(picked.end(), lb.begin(), lb.end());
                }
            }
        }
        if (!bad && (picked.size() < opcnt_v)) {
            opcnt_v = picked.size();
            ansoplist = picked;
        }
    }

    if (opcnt_v == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << opcnt_v << '\n';
        for (int i = 0 ; i < opcnt_v ; i ++) {
            cout << ansoplist[i] + 1 << " \n"[i == opcnt_v - 1];
        }
    }
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