/*
[1, n] 中
- 有 n / m 个数能被 m 整除
- 有 n / m + (n % m >= i ? 1 : 0) 个数模 m 余 i
平方一下，再组合一下 
*/

int T;
LL n, m, cnt[N];

void solve1() {
    cin >> n >> m;
    cnt[0] += n / m;
    for (int i = 1; i < m; i++) {
        LL c = n / m + (n % m >= i ? 1 : 0);
        cnt[i * i % m] += c;
    }
    LL res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % m == 0) {
                res += cnt[i] * cnt[j];
            }
        }
    }
    cout << res << "\n";
}       