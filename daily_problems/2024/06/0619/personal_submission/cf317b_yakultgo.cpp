#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n, m, cnt[2 * N][2 * N];
bool vis = 1;

int main() {
    cin >> n >> m;
    cnt[N][N] = n;
    while (vis) {
        vis = 0;
        for (int i = 0; i < N * 2; i++) {
            for (int j = 0; j < N * 2; j++) {
                if (cnt[i][j] >= 4) {
                    vis = 1;
                    int num = cnt[i][j] / 4;
                    cnt[i - 1][j] += num;
                    cnt[i + 1][j] += num;
                    cnt[i][j - 1] += num;
                    cnt[i][j + 1] += num;
                    cnt[i][j] -= (num * 4);
                }
            }
        }
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (0 <= (x + 105) && (x + 105) < 2 * N && 0 <= (y + 105) && (y + 105) < 2 * N) {
            cout << cnt[x + 105][y + 105] << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}