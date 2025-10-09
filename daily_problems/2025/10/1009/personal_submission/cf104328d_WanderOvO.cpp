/*
其实就是看树中是否存在一条长 >= n / 2 的路径，使得 gcd > 1
倘若树本身就没有这么长的链，当然是不行的
我们考虑以某个点 i 为最高点，其往下至多走多少步还可以是 gcd > 1 的
应该考虑从 i 开始往下走两条链，并且这两条链上的最大公约数的最大公约数不能是 1
每个数至多有十几种素因子，并且可以预处理每个数的最小素因子，所以可以快速进行素因数分解
设 dp[i][j][0/1] 为以 i 为最高点往下走，素因子包含 j 的最长和次长链有多长
可以定义 map<int, int> dp0[N], dp1[N]， 这样我们会有一个双 log 的做法
*/ 

map<int, int> dp0[M], dp1[M];
int from[M][2];
int primes[N], cnt, min_p[N];
bool is_prime[N];
int n, a[M];
vector<vector<int>> e(M);

void dfs(int u, int fa) {
    vector<int> p_factors;
    int val = a[u];
    while (min_p[val] != 1) {
        int p = min_p[val];
        p_factors.push_back(p);
        while (val % p == 0) {
            val /= p;
        }
    }
    for (auto p : p_factors) {
        dp0[u][p] = 1;
        dp1[u][p] = 0;
    }

    for (auto v : e[u]) {
        if (v != fa) {
            dfs(v, u);
            for (auto p : p_factors) {
                if (dp0[v].count(p)) {
                    if (dp0[v][p] + 1 > dp0[u][p]) {
                        dp1[u][p] = dp0[u][p];
                        from[u][1] = from[u][0];
                        dp0[u][p] = dp0[v][p] + 1;
                        from[u][0] = v;
                    } else if (dp0[v][p] + 1 > dp1[u][p]) {
                        dp1[u][p] = dp0[v][p] + 1;
                        from[u][1] = v;
                    }   
                }
            }
        }
    }
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i = 2; i < N; i++) {
        is_prime[i] = true;
    }
    min_p[1] = 1;
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            primes[cnt++] = i;
            min_p[i] = i;
        }
        for (int j = 0; j < cnt && i * primes[j] < N; j++) {
            is_prime[i * primes[j]] = false;
            min_p[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) {
                break;
            }
        }
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        for (auto &it : dp0[i]) {
            int p = it.first;
            if (dp1[i][p] == 0) {
                if (dp0[i][p] > n / 2) {
                    cout << "YES\n";
                    return;
                }
            } else {
                if (dp0[i][p] + dp1[i][p] - 1 > n / 2) {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }

    cout << "NO\n";
}   
