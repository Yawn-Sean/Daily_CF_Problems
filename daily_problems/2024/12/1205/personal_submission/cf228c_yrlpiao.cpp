#include <iostream>
#include <cstring>
using namespace std;
const int N = 500 + 10;

int arr[N][N], a[N][N], b[N][N];

int main() {
    memset(a, -1, sizeof a);
    memset(b, -1, sizeof a);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            arr[i][j] = c == '*';
        }
    }
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j + 1 < m; j++) {
            a[i][j] = 0;
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    a[i][j] *= 2;
                    a[i][j] += arr[i + x][j + y];
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < 8; i++) {
        int sz = 1 << i;
        for (int i = 0; i + sz * 2 <= n; i++) {
            for (int j = 0; j + sz * 2 <= m; j++) {
                int s = 0;
                for (int x = 0; x < 2; x++) {
                    for (int y = 0; y < 2; y++) {
                        s *= 2;
                        s += a[i + x * sz][j + y * sz] == 15;
                    }
                }
                int flg = 1;
                for (int x = 0; x < 2; x++) {
                    for (int y = 0; y < 2; y++) {
                        if (a[i + x * sz][j + y * sz] != 15 && a[i + x * sz][j + y * sz] != s) flg = 0;
                    }
                }
                if (flg) b[i][j] = s;
            }
        }

        for (int i = 0; i + sz * 2 <= n; i++) {
            for (int j = 0; j + sz * 2 <= m; j++) {
                if ((a[i][j] = b[i][j]) != -1) ans++;
                b[i][j] = -1;
            }
        }
    }
    cout << ans;
}
