/*
连一条链，然后再加多余的边，链上的边权尽可能小，多余的边的边权尽可能大
如果 n - 1 是素数，则全都连 1 就行，其他的边连特别大的
如果 n - 1 是合数，则找 >= n - 1 的最大素数 p，(n - 1, n) 连 p - n + 2
其他边连无穷大
*/

void solve1() {
    get_prime();
    cin >> n >> m;
    int pos = lower_bound(prime, prime + cnt, n - 1) - prime;
    int p = prime[pos];
    cout << p << " " << p << "\n";
    for (int i = 1; i < n - 1; i++, m--) {
        cout << i << " " << i + 1 << " " << "1\n";
    }
    m--;
    cout << n - 1 << " " << n << " " << p - n + 2 << "\n";
    for (int i = 1; i <= n && m > 0; i++) {
        for (int j = i + 2; j <= n && m > 0; j++) {
            m--;
            cout << i << " " << j << " " << INF << "\n";
        }
    }
}