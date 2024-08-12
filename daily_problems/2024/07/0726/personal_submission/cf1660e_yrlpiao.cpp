#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
const int N = 2000 + 10;

string g[N * 2];

void yrlpSolve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> g[i];
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = min(i, j);
            if (i - x) x = n - i + x;
            else x = j - x;
            ans[x] += g[i][j] == '1';
        }
    }
    int s = accumulate(ans.begin(), ans.end(), 0);
    int mx = *max_element(ans.begin(), ans.end());
    cout << n + s - 2 * mx << endl;
}

signed main() {
    int T = 1; cin >> T;
    while (T--) yrlpSolve();
}
