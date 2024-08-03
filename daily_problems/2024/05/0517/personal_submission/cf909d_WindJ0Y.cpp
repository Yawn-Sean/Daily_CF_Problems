#include <bits/stdc++.h>
using namespace std;

void work() {
    
    string str; cin >> str;

    vector<pair<int, int>> lines;
    for (auto elm : str) {
        if (lines.empty() || lines.back().first != elm) {
            lines.emplace_back(elm, 1);
        } else {
            lines.back().second++;
        }
    }

    int ans = 0;
    while (lines.size() > 1) {
        ans ++;
        vector<pair<int, int>> new_lines;
        for (int i = 0 ; i < lines.size() ; i++) {
            auto cur_par = lines[i];
            cur_par.second --;
            if (i && i != lines.size() - 1 && cur_par.second) {
                cur_par.second --;
            }
            if (!cur_par.second) {
                continue;
            }
            if (new_lines.empty() || new_lines.back().first != cur_par.first) {
                new_lines.emplace_back(cur_par);
            } else {
                new_lines.back().second += cur_par.second;
            }
        }
        lines = new_lines;
    }

    cout << ans << "\n";

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