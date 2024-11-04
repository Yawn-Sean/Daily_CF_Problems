const int N = 1e5+10;
int n;
int primes[N], cnt;
bool st[N];
int f[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
    st[0] = st[1] = true;
}
void solve() {
    cin >> n;
    get_primes(n);
    for (int i = 4; i <= n; i += 2) {
        for (int j = 0; j < cnt and primes[j] < i; j ++) {
            if (!st[i - primes[j]]) {
                f[i] = primes[j];
                break;
            }
        }
    }
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    vector<int> seen(n + 1);
    vector<pii> res;
    
    auto add = [&](int x, int y) {
        if (x > y) swap(x, y);
        if (!st[y - x + 1]) {
            res.emplace_back(x, y);
            return;
        }
        if ((y - x) % 2) {
            res.emplace_back(x, x + 1);
            int d = (y - x + 1);
            int d1 = f[d];
            res.emplace_back(x + 1, x + d1);
            res.emplace_back(x + d1, y);
            res.emplace_back(x + 1, x + d1);
            res.emplace_back(x, x + 1);
        }
        else {
            int d = (y - x + 2);
            int d1 = f[d];
            res.emplace_back(x, x + d1 - 1);
            res.emplace_back(x + d1 - 1, y);
            res.emplace_back(x, x + d1 - 1);
        }
    };
    
    for (int i = 1; i <= n; i ++) {
        if (seen[i]) continue;
        int x = i;
        vector<int> cur = {x};
        seen[x] = true;
        while (!seen[a[x]]) {
            cur.push_back(a[x]);
            seen[a[x]] = true;
            x = a[x];
        }
        while (sz(cur) > 1) {
            int p1 = cur.back();
            cur.pop_back();
            int p2 = cur.back();
            cur.pop_back();
            swap(a[p1], a[p2]);
            add(p1, p2);
            if (a[p1] != p1) cur.pbk(p1);
            if (a[p2] != p2) cur.pbk(p2);
        }
    }
    cout << sz(res) << endl;
    cout << res << endl;
}