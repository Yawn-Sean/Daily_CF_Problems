/*
假如这个是成立的，那 g = gcd(a[1], a[2])
每个 a[i] 应该都能整除 g
并且任取两个 a[i] / g，他们的 gcd 应该 = 1
先求出来 b[i] = a[i] / g
对于 b[i]，统计每个数出现的次数
枚举 i 从 2 到 1e7，看 i 的倍数出现的次数，如果 >= 2 次，说明还有 gcd 不为 1 的对
*/ 

int n, a[N], cnt[N], primes[N], idx;
bool is_prime[N];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int g = gcd(a[1], a[2]);
    for (int i = 1; i <= n; i++) {
        if (a[i] % g != 0) {
            cout << "NO\n";
            return;
        }
        a[i] /= g;
        cnt[a[i]]++;
    }

    memset(is_prime, 1, sizeof is_prime);
    is_prime[1] = false;
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            primes[idx++] = i;
        }
        for (int j = 0; j < idx && i * primes[j] < N; j++) {
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }

    for (int i = 0; i < idx; i++) {
        int val = primes[i];
        int s = 0;
        for (int j = val; j < N; j += val) {
            s += cnt[j];
        }
        if (s > 1) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}  
