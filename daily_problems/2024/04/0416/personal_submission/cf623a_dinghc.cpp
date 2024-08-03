#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    vector<int> g(n, 0);
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        g[x - 1]++;
        g[y - 1]++;
        matrix[x - 1][y - 1] = matrix[y - 1][x - 1] = 1;
    }

    vector<int> s(n, 1);
    auto check = [&] () -> bool {
        for (int i = 0; i < n; i++) {
            if (s[i] == 1 && g[i] < n - 1) {
                deque<int> q;
                q.push_back(i);
                s[i] = 0;
                while (!q.empty()) {
                    int u = q.front(); q.pop_front();
                    for (int v = 0; v < n; v++) {
                        if (u == v) continue;
                        if (matrix[u][v] == 0) {
                            if (s[v] == 1) {
                                q.push_back(v);
                                s[v] = s[u] ^ 2;
                            } else if (s[v] != (s[u] ^ 2)) {
                                return false;
                            }
                        } else if (s[v] == (s[u] ^ 2)) {
                            return false;
                        }
                    }
                }
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 1 && g[i] < n - 1) {
                return false;
            }
        }
        return true;
    };

    if (check()) {
        cout << "Yes\n";
        string ans(n, '\0');
        for (int i = 0; i < n; i++) ans[i] = static_cast<char>('a' + s[i]);
        cout << ans << "\n";
    } else {
        cout << "No\n";
    }

    return 0;
}

