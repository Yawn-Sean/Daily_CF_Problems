/*
假如一个图不连通，则其补图肯定连通
不妨设 u, v 不连通，则补图中 u 的连通分量里每个点都会连 v，v 里的会连 u，然后 u, v 会直接相连
所以 a > 1 && b > 1 一定无解
考虑会不会 a = 1 且 b = 1
n = 1 时可以，n >= 4 时可以，只需要连一条链即可。n = 2, 3 时无解
考虑 a = 1 && b > 1，则只需要选 b - 1 个点，把所有其他点都连满即可，但前提是 n >= 2
考虑 a > 1 && b = 1，则只需要留出 a - 1 个孤立点，其他的部分连成一条链即可，但前提是 n >= 2
*/

int n, a, b;

void solve1() {
    cin >> n >> a >> b;
    vector<vector<int>> res(n + 1, vector<int>(n + 1, 0));
    if (a > 1 && b > 1) {
        cout << "NO\n";
        return;
    } else {
        if (a == 1 && b == 1) {
            if (n == 2 || n == 3) {
                cout << "NO\n";
                return;
            } else {
                for (int i = 1; i < n; i++) {
                    res[i][i + 1] = 1;
                    res[i + 1][i] = 1;
                }
            }
        } else if (a == 1 && b > 1) {
            for (int i = 1; i <= b - 1; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i != j) {
                        res[i][j] = 1;
                        res[j][i] = 1;
                    }
                }
            }
        } else {
            for (int i = a; i < n; i++) {
                res[i][i + 1] = 1;
                res[i + 1][i] = 1;
            }
        } 
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << res[i][j];
        }
        cout << '\n';
    }
}                                                                                                                  
