const int N = 2e6+10;
int n;
int primes[N], cnt, fact[N];
bool st[N];

void get_primes(int n) {
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i, fact[i] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            fact[primes[j] * i] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}
void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    cin >> a;
    
    get_primes(2000000);
    
    vector<int> seen(N, false);
    vector<int> ps;
    auto check = [&](int x) -> bool {
        ps.clear();
        while (x > 1) {
            ps.push_back(fact[x]);
            x /= fact[x];
        }
        for (auto x : ps) {
            if (seen[x]) return false;
        }
        return true;
    };
    
    int pos = -1;
    for (int i = 0; i < n; i ++) {
        bool ok = check(a[i]);
        if (!ok) {
            pos = i;
            break;
        }
        for (auto x : ps) {
            seen[x] = true;
        }
        b[i] = a[i];
    }
    
    if (pos == -1) {
        cout << b << endl;
        return;
    }
    
    // 找到比现在大的第一个数
    for (int i = a[pos] + 1; i < 2000000; i ++) {
        bool ok = check(i);
        if (!ok) continue;
        b[pos] = i;
        for (auto x : ps) {
            seen[x] = true;
        }
        break;
    }
    
    // 后面每个都找最小的质数
    for (int i = pos + 1, j = 0; i < n; i ++) {
        while (j < cnt and seen[primes[j]]) j ++;
        b[i] = primes[j ++];
    }
    
    cout << b << endl;
}