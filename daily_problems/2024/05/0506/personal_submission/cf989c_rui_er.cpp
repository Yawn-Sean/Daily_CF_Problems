int a, b, c, d, A[105][105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> b >> c >> d;
    --a; --b; --c; --d;
    rep(i, 1, 25) rep(j, 1, 25) A[i][j] = 0;
    rep(i, 1, 25) rep(j, 26, 50) A[i][j] = 1;
    rep(i, 26, 50) rep(j, 1, 25) A[i][j] = 2;
    rep(i, 26, 50) rep(j, 26, 50) A[i][j] = 3;
    for(int x = 1, y = 1; d; --d) {
        A[x][y] = 3;
        y += 2;
        if(y > 25) x += 2, y -= 25;
    }
    for(int x = 1, y = 26; c; --c) {
        A[x][y] = 2;
        y += 2;
        if(y > 50) x += 2, y -= 25;
    }
    for(int x = 26, y = 1; b; --b) {
        A[x][y] = 1;
        y += 2;
        if(y > 25) x += 2, y -= 25;
    }
    for(int x = 26, y = 26; a; --a) {
        A[x][y] = 0;
        y += 2;
        if(y > 50) x += 2, y -= 25;
    }
    cout << 50 << " " << 50 << endl;
    rep(i, 1, 50) {
        rep(j, 1, 50) cout << char('A' + A[i][j]);
        cout << endl;
    }
    return 0;
}
