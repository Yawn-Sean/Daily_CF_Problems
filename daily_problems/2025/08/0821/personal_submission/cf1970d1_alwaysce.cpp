#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
    std::mt19937 rng(time(nullptr));
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<vector<int>> record(n, vector<int>(n));

    while (true) {
        vector<string> strs(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 20; j++) {
                strs[i] += (rng() & 1) ? 'X' : 'O';
            }
        }

        set<int> vis;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                string tmp = strs[i] + strs[j];

                set<string> st;
                for (int x = 0; x < tmp.size(); x++) {
                    for (int y = x; y < tmp.size(); y++) {
                        st.insert(tmp.substr(x, y - x + 1));
                    }
                }

                record[i][j] = st.size();
                vis.insert(record[i][j]);
            }
        }

        if (vis.size() == n * n) {
            for (auto & s: strs) {
                cout << s << endl;
            }
            break;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int target;
        cin >> target;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (record[i][j] == target) {
                    cout << i + 1 << " " << j + 1 << endl;
                }
            }
        }
    }
    return 0;
}
