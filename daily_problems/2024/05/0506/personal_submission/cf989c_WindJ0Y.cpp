#include <bits/stdc++.h>
using namespace std;

void work() {
    int a, b, c, d; cin >> a >> b >> c >> d;

    vector<vector<int>> ans(50, vector<int>(50));

    vector<int> dx = {0, 0, 25, 25};
    vector<int> dy = {0, 25, 0, 25};
    vector<int> v = {0, 1, 2, 3};
    vector<int> lft = {d - 1, c - 1, b - 1, a - 1};

    for (int p = 0; p < 4; p++) {
        for (int i = dx[p]; i < dx[p] + 25; i ++) {
            for (int j = dy[p]; j < dy[p] + 25; j ++) {
                ans[i][j] = v[p];
                if (i % 2 == 0 && j % 2 == 0 && lft[p] > 0) {
                    lft[p] --;
                    ans[i][j] = 3 - v[p];
                }
            }
        }
    }

    cout << "50 50 \n";
    for (auto line : ans) {
        for (auto v : line) {
            cout << "ABCD"[v];
        }
        cout << "\n";
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