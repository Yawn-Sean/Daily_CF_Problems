#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n);
    for (int i = 0; i < m; i++) {
        char op;
        int id;
        cin >> op >> id;
        --id;

        if (op == '+') {
            vec[id].push_back(i + 1);
        } else {
            if (vec[id].empty()) {
                vec[id].push_back(0);
            }
            // interval = [l, r] 
            int r = i + 1;
            vec[id].push_back(-r);
        }
    }

    vector<int> diff(m + 2, 0);
    for (int i = 0; i < n; i++) {
        if (vec[i].size() & 1) {
            vec[i].push_back(-(m + 1));
        }

        for (int j = 0; j < vec[i].size(); j += 2) {
            int l = vec[i][j];
            int r = -vec[i][j + 1];
            diff[l]++;
            diff[r]--;
        }
    }

    int num = 0;
    for (int i = 0; i <= m; i++) {
        if (diff[i] > 0) { num++; }
        diff[i + 1] += diff[i];
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (vec[i].empty()) {
            ans.push_back(i + 1);
        } else {
            int cur = num;
            for (auto& x: vec[i]) {
                cur += x;
            }
            if (cur == 0) {
                ans.push_back(i + 1);
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto& x: ans) {
        cout << x << " ";
    }
    return 0;
}
