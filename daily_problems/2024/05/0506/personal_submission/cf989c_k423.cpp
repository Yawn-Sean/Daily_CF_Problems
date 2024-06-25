// https://codeforces.com/contest/989/submission/259710589

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
 
    int N = 9, M = 49;
 
    auto f = [&](char bg, char fr, int cnt) {
        vector<string> g(N, string(M, bg));
        for (int i = 1; i + 1 < N; i += 2) {
            for (int j = 0; j < M && cnt; j += 2, cnt--) {
                g[i][j] = fr;
            }
        }
        for (auto &s: g) cout << s << endl;
    };
 
    cout << N * 4 << ' ' << M << endl;
    f('A', 'B', b - 1);
    f('B', 'A', a - 1);
    f('C', 'D', d - 1);
    f('D', 'C', c - 1);
}
