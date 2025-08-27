/*
图中如果存在奇数元环，则扮演 Alice，每次只给 1 和 2 这两种颜色，最后必定能逼死 Bob，相当于二分图判定
图中不存在奇数元环，则图是二分图，我们可以先把左部和右部中存在哪些点预处理出来
如果 Alice 每次都让我们只选 1 和 2 中的某个颜色，则我们直接左部涂 1，右部涂 2 即可

如果 Alice 把三种颜色都告诉过我们，考虑第一组她告诉我们的颜色是什么
假设是 u, v，则 6 - u - v 就是没告诉我们的颜色
我们强制，左部的点涂 1，右部的点涂 2
我们强制，当某个部的点没涂满颜色时，总是用 1 或者 2 填
一旦某个部的颜色填满了，才可以选 3，这样保证了 3 只在某个部出现
*/

int n, m, color[N];
vector<vector<int>> e(N);

bool dfs(int u, int c) {
    color[u] = c;
    bool res = true;
    for (auto v : e[u]) {
        if (color[v] == -1) {
            res &= dfs(v, 1 - c);
        } else {
            if (color[v] == color[u]) {
                return false;
            }
        }
    }
    return res;
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        color[i] = -1;
    }
    if (!dfs(1, 0)) {
        cout << "Alice" << endl;
        for (int i = 1; i <= n; i++) {
            cout << "1 2" << endl;
            int u, v;
            cin >> u >> v;
        }
    } else {
        cout << "Bob" << endl;
        vector<int> l, r;
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) {
                l.push_back(i);
            } else {
                r.push_back(i);
            }
        }

        for (int i = 1; i <= n; i++) {
            int a, b;
            cin >> a >> b;
            bool has1 = (a == 1 || b == 1), has2 = (a == 2 || b == 2), has3 = (a == 3 || b == 3);

            if (has1 && l.size() > 0) {
                cout << l.back() << " 1" << endl;
                l.pop_back();
            } else if (has2 && r.size() > 0) {
                cout << r.back() << " 2" << endl;
                r.pop_back();
            } else {
                if (l.size() == 0) {
                    if (has2) {
                        cout << r.back() << " 2" << endl;
                    } else {
                        cout << r.back() << " 3" << endl;
                    }
                    r.pop_back();
                } else if (r.size() == 0) {
                    if (has1) {
                        cout << l.back() << " 1" << endl;
                    } else {
                        cout << l.back() << " 3" << endl;
                    }
                    l.pop_back();
                } else {
                    assert(0 == 1);
                }
            }
        }
    }
}
