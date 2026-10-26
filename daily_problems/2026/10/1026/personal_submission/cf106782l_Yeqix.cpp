#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

vector<int> dx{1, -1, 0, 0};
vector<int> dy{0, 0, 1, -1};
vector<array<char, 2>> d{{'U', 'D'}, {'D', 'U'}, {'L', 'R'}, {'R', 'L'}};

int up = 0;
int cnt = 0;
char query(int x, int y) {
    cnt++;
    assert(cnt <= up);
    cout << "? " << x << " " << y << "\n";
    cout.flush();
    char z;
    cin >> z;
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    up = n * m / 4;
    int sum = n * m;
    vector<vector<char>> f(n, vector<char>(m, '?'));
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (f[i - 1][j] == '?' && f[i][j - 1] == '?' && f[i][j] == '?' && f[i - 1][j - 1] == '?') {
                f[i][j] = query(i + 1, j + 1);
                if (f[i][j] == 'U') {
                    f[i + 1][j] = 'D';
                } else if (f[i][j] == 'D') {
                    f[i - 1][j] = 'U';
                } else if (f[i][j] == 'L') {
                    f[i][j + 1] = 'R';
                } else {
                    f[i][j - 1] = 'L';
                }
                sum -= 2;
            }
        }
    }

    auto check = [&]() -> void {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (f[i][j] == '?') {
                    vector<int> v;
                    for (int k = 0; k < 4; k++) {
                        int ex = i + dx[k], ey = j + dy[k];
                        if (ex < n && ey < m && ex >= 0 && ey >= 0 && f[ex][ey] == '?') {
                            v.push_back(k);
                        }
                    }
                    if (v.size() == 1) {
                        auto [f1, f2] = d[v[0]];
                        sum -= 2;
                        f[i][j] = f1, f[i + dx[v[0]]][j + dy[v[0]]] = f2;
                    }
                }
            }
        }
    };

    while (sum) {
        check();
        int vis = 0;
        for (int i = 0; i < n && !vis; i++) {
            for (int j = 0; j < m && !vis; j++) {
                if (f[i][j] == '?') {
                    f[i][j] = query(i + 1, j + 1);
                    if (f[i][j] == 'U') {
                        f[i + 1][j] = 'D';
                    } else if (f[i][j] == 'D') {
                        f[i - 1][j] = 'U';
                    } else if (f[i][j] == 'L') {
                        f[i][j + 1] = 'R';
                    } else {
                        f[i][j - 1] = 'L';
                    }
                    vis = 1;
                    sum -= 2;
                }
            }
        }
    }

    cout << "!\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << f[i][j];
        }
        cout << "\n";
    }
    return 0;
}