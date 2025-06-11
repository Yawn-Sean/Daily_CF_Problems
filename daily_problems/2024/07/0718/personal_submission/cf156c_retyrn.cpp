int n;
string s;
int f[110][2510];

void solve() {
    cin >> s;
    n = sz(s);
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    int sum = 0;
    for (auto c : s) {
        sum += (c - 'a');
    }
    cout << (f[n][sum] - 1 + mod) % mod << endl;
}
int main() {
    FAST;
    
    f[0][0] = 1;
    for (int i = 0; i < 100; i ++) {
        for (int j = 0; j <= 2500; j ++) {
            if (f[i][j] == 0) continue;
            for (int k = 0; k + j <= 2500 and k < 26; k ++) {
                f[i + 1][k + j] = (f[i + 1][k + j] + f[i][j]) % mod;
            }
        }
    }
    Tsolve();

    return 0;
}