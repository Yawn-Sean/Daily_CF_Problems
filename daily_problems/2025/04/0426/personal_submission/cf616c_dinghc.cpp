#include <bits/stdc++.h>
 
using namespace std;

struct dsu {
    int _n;
    vector<int> parent_or_size;
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}
    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }
    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }
    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }
    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }
};

constexpr int N = 1000;
char grid[N][N + 1];
pair<int, int> dirs[4] { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }
    dsu d(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (grid[i][j] == '.') {
            int idx1 = i * m + j;
            for (auto&[dx, dy] : dirs) {
                int nx = dx + i, ny = dy + j;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.') {
                    int idx2 = nx * m + ny;
                    d.merge(idx1, idx2);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (grid[i][j] == '*') {
            set<int> le;
            for (auto&[dx, dy] : dirs) {
                int nx = dx + i, ny = dy + j;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.') {
                    le.insert(d.leader(nx * m + ny));
                }
            }
            int k = 1;
            for (auto& l : le) {
                k += d.size(l);
            }
            grid[i][j] = k % 10 + '0';
        }
        printf("%s\n", grid[i]);
    }
    return 0;
}


