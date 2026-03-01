std::vector<int> minp, primes, cnt;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    cnt.assign(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            cnt[i] = 1;
            primes.push_back(i);
        }

        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                cnt[i * p] = cnt[i];
                break;
            } else {
                cnt[i * p] = cnt[i] + 1;
            }
        }
    }
}
int N = 1e6;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto is_inc = [&]() -> bool {
        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] < a[i]) {
                return false;
            }
        }
        return true;
    };

    if (is_inc()) {
        cout << "Bob\n";
        return;
    }
    bool alice = false;
    for (int &x: a) {
        if (cnt[x] > 1) {
            alice = true;
        }
        x = minp[x];
    }
    if (alice) {
        cout << "Alice\n";
    } else {
        cout << (is_inc() ? "Bob\n" : "Alice\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(N);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
