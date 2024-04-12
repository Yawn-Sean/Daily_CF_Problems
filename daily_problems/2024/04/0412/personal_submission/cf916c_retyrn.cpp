// 线性筛
int primes[maxn], cnt;
bool st[maxn];

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        // 从小到大枚举所有的质数
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            // primes[j]是i的最小质因子
            if (i % primes[j] == 0) break;
        }
    }
}
int n, m;

void solve() {
    // 让1-n成为最小生成树
    // 找到大于等于n的第一个质数
    cin >> n >> m;
    get_primes(n * 2);
    int t = n;
    while (t < n * 2 and st[t]) {
        t ++;
    }
    cout << t << ' ' << t << endl;
    for (int i = 1; i < n; i ++) {
        // 只输出1和2
        int u = t / (n - i) + (t % (n - i) > 0);
        cout << i << ' ' << i + 1 << ' ' << u << endl;
        t -= u;
        m --;
    }
    for (int i = 1; i <= n and m > 0; i ++) {
        for (int j = i + 2; j <= n and m > 0; j ++) {
            cout << i << ' ' << j << ' ' << 1000000000 << endl;
            m --;
        }
    }
}