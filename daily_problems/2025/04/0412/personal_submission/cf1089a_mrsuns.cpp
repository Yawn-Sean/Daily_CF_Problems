int f(int a, int b, int c, int d) {
    return ((a * 201 + b) * 4 + c) * 4 + d;
}
array<int, 4> g(int x) {
    return { x / 4 / 4 / 201,x / 4 / 4 % 201,x / 4 % 4,x % 4 };
}
vector<int> dp(f(200, 200, 3, 3) + 1, -1);

void Prework() {
    queue<int> q;
    q.push(f(0, 0, 0, 0));
    while (q.size()) {
        auto x = q.front();q.pop();
        auto [A, B, C, D] = g(x);
        int p = (C + D < 4) ? 25 : 15;

        if (C < 3 and D < 3) {
            if (A + p <= 200) {
                for (int i = 0;i <= p - 2;i++) {
                    if (B + i <= 200) {
                        int nx = f(A + p, B + i, C + 1, D);
                        if (dp[nx] == -1) {
                            dp[nx] = x;
                            q.push(nx);
                        }
                    }
                }
            }
            for (int i = p + 1;i <= 200;i++) {
                if (A + i > 200) break;
                if (B + i - 2 > 200) break;
                int nx = f(A + i, B + i - 2, C + 1, D);
                if (dp[nx] == -1) {
                    dp[nx] = x;
                    q.push(nx);
                }
            }

            if (B + p <= 200) {
                for (int i = 0;i <= p - 2;i++) {
                    if (A + i <= 200) {
                        int nx = f(A + i, B + p, C, D + 1);
                        if (dp[nx] == -1) {
                            dp[nx] = x;
                            q.push(nx);
                        }
                    }
                }
            }
            for (int i = p + 1;i <= 200;i++) {
                if (B + i > 200) break;
                if (A + i - 2 > 200) break;
                int nx = f(A + i - 2, B + i, C, D + 1);
                if (dp[nx] == -1) {
                    dp[nx] = x;
                    q.push(nx);
                }
            }
        }
    }
}
void Solve() {
    int a, b;cin >> a >> b;
    int c = -1, d = -1;
    for (int i = 0;i <= 2;i++) {
        if (dp[f(a, b, 3, i)] != -1) {
            c = 3, d = i;
            break;
        }
    }
    if (d == -1) {
        for (int i = 2;i >= 0;i--) {
            if (dp[f(a, b, i, 3)] != -1) {
                c = i, d = 3;
                break;
            }
        }
    }
    if (c == -1) {
        cout << "Impossible\n";
        return;
    }
    cout << c << ":" << d << endl;
    int round = c + d;
    vector<array<int, 2>> op;
    int x = f(a, b, c, d);
    for (int t = 0;t < round;t++) {
        int nx = dp[x];
        auto [na, nb, nc, nd] = g(nx);
        //cout << "BUG:" << na << " " << nx << endl;
        op.push_back({ a - na,b - nb });
        tie(a, b, c, d, x) = make_tuple(na, nb, nc, nd, nx);
    }
    reverse(op.begin(), op.end());
    for (auto [x, y] : op) {
        cout << x << ":" << y << " ";
    }
    cout << endl;
}

