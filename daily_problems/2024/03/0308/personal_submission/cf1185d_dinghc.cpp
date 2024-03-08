#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int n;
    cin >> n;

    vector<int> b(n);
    for (auto& bi : b) {
        cin >> bi;
    }

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    
    ranges::sort(indices, [&] (int x, int y) {
        return b[x] < b[y];
    });

    int ans = -1;
    if (n <= 3) {
        ans = indices[0] + 1;
    } else {
        function<bool(int, int)> check_diff = [&] (int k, int d) -> bool {
            bool is_same = true;
            for (int i = k; i < n; i++) {
                if (b[indices[i]] - b[indices[i - 1]] != d) {
                    is_same = false;
                    break;
                }
            }
            return is_same;
        };
        
        int d1 = b[indices[1]] - b[indices[0]];
        int d2 = b[indices[2]] - b[indices[1]];
        int d3 = b[indices[3]] - b[indices[2]];

        if (d1 == d2 && d2 == d3) {
            int d = d1;
            int last = b[indices[3]];
            int diff_cnt = 0;
            int idx = -1;
            for (int i = 4; i < n; i++) {
                if (b[indices[i]] - last != d) {
                    diff_cnt++;
                    idx = indices[i];
                } else {
                    last = b[indices[i]];
                }
            }
            
            if (diff_cnt == 0) {
                ans = indices[0] + 1;
            } else if (diff_cnt == 1) {
                ans = idx + 1;
            }
        } else {
            if (ans == -1 && d2 == d3) {
                int d = d2;
                // if all same d from b[indices[4]] - b[indices[3]]
                if (check_diff(4, d)) {
                    ans = indices[0] + 1;
                }
            }
            if (ans == -1 && d1 == d2) {
                int d = d1;
                if (n == 4) {
                    ans = indices[3] + 1;
                } else if (b[indices[4]] - b[indices[2]] == d) {
                    // if all same d from b[indices[5]] - b[indices[4]]
                    if (check_diff(5, d)) {
                        ans = indices[3] + 1;
                    }
                }
            }
            if (ans == -1 && d1 == d2 + d3) {
                int d = d1;
                // if all same d from b[indices[4]] - b[indices[3]]
                if (check_diff(4, d)) {
                    ans = indices[2] + 1;
                }
            }
            if (ans == -1 && d3 == d1 + d2) {
                int d = d3;
                // if all same d from b[indices[4]] - b[indices[3]]
                if (check_diff(4, d)) {
                    ans = indices[1] + 1;
                }
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
