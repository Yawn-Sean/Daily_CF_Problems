// https://codeforces.com/problemset/submission/749/257936721
#include <bits/stdc++.h>
using namespace std;

void work() {
    int n; cin >> n;
    
    vector<vector<int>> works(n + 1);
    vector<pair<int, int>> mxv(n + 1);

    for (int i = 1; i <= n; i++) {
        mxv[i].second = i;
        int pid, num; cin >> pid >> num;
        works[pid].push_back(num);
        mxv[pid].first = num;
    }

    sort(mxv.begin(), mxv.end(), greater<pair<int, int>>());

    vector<int> pid_order;
    vector<int> pid_pos(n + 1, -1);

    for (auto [v, pid] : mxv) {
        if (v == 0) break;
        pid_pos[pid] = pid_order.size();
        pid_order.push_back(pid);
    }

    int q; cin >> q;
    while (q--) {
        int l; cin >> l;
        vector<int> nums(l);

        for (int i = 0 ; i < l; i++) {
            cin >> nums[i];
        }

        for (auto elm: nums) {
            int pos = pid_pos[elm];
            if (pos != -1) {
                pid_order[pos] = -1;
            }
        }

        int winner_id = -1;
        int laoer_id = -1;

        for (auto elm : pid_order) {
            if (elm == -1) continue;
            if (winner_id == -1) {
                winner_id = elm;
            } else {
                laoer_id = elm;
                break;
            }
        }

        if (winner_id == -1 && laoer_id == -1) {
            cout << "0 0\n";
        } else {
            int laoer_max = ((laoer_id == -1) ? -1 : works[laoer_id].back());
            int winner_v = *upper_bound(works[winner_id].begin(), works[winner_id].end(), laoer_max);
            cout << winner_id << " " << winner_v << "\n";
        }

        for (auto elm: nums) {
            int pos = pid_pos[elm];
            if (pos != -1) {
                pid_order[pos] = elm;
            }
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