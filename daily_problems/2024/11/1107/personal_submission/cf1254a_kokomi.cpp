#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const string CHARS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

void solve() {
    int r, c, k;
    cin >> r >> c >> k;
    
    vector<string> grid(r);
    int rice_count = 0;
    
    for (int i = 0; i < r; ++i) {
        cin >> grid[i];
        rice_count += count(grid[i].begin(), grid[i].end(), 'R');
    }
    
    int base_rice = rice_count / k;
    int extra_rice = rice_count % k;
    
    vector<vector<char>> result(r, vector<char>(c));
    int rice_per_chicken = 0, chicken_index = 0, rice_assigned = 0;
    bool left_to_right = true;
    
    for (int i = 0; i < r; ++i) {
        if (left_to_right) {
            for (int j = 0; j < c; ++j) {
                result[i][j] = CHARS[chicken_index];
                if (grid[i][j] == 'R') {
                    ++rice_assigned;
                }
                
                if (rice_assigned == (base_rice + (chicken_index < extra_rice ? 1 : 0))) {
                    rice_assigned = 0;
                    ++chicken_index;
                    if (chicken_index >= k) chicken_index = k - 1;
                }
            }
        } else {
            for (int j = c - 1; j >= 0; --j) {
                result[i][j] = CHARS[chicken_index];
                if (grid[i][j] == 'R') {
                    ++rice_assigned;
                }
                
                if (rice_assigned == (base_rice + (chicken_index < extra_rice ? 1 : 0))) {
                    rice_assigned = 0;
                    ++chicken_index;
                    if (chicken_index >= k) chicken_index = k - 1;
                }
            }
        }
        left_to_right = !left_to_right;
    }
    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << result[i][j];
        }
        cout << "\n";
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
