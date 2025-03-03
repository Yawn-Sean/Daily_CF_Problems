/*
对分子和分母的所有数做素因数分解，复杂度是 O((n + m)sqrt(1e7))，实际上算起来常数会特别大
由于值域 = 1e7，因此考虑预处理 1e7 以内的素数，以及每个数的最小素因子 minp
对于一个数 i，利用线性筛求出其最小素因子是 minp[i]，因此记录其一个素因子为 minp[i]，然后 i /= minp[i]
这样保证了 log 次就可以因数分解完，因为每次至少除以 2
素因数分解完成后，用 map 分别存分子和分母的因子，消去相同的，然后分别再乘起来
乘起来重新构造的数组长度可能超过 1e5，不满足题意
羊的构造：直接在原数组上除掉应该被约掉的素因子，这样长度肯定满足题意
*/

int n, m, a[N], b[N];
map<int, int> pf1, pf2, del1, del2;
int primes[M], idx, minp[M];
bool is_prime[M];

void get_primes(int n) {
    memset(is_prime, 1, sizeof is_prime);
    is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes[idx++] = i;
            minp[i] = i;
        }
        for (int j = 0; j < idx && i <= n / primes[j]; j++) {
            minp[i * primes[j]] = primes[j];
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0) {
                break;
            }
        } 
    }
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    get_primes(M - 1);

    for (int i = 1; i <= n; i++) {
        int val = a[i];
        while (val > 1) {
            pf1[minp[val]]++;
            val /= minp[val];
        }
    }

    for (int i = 1; i <= m; i++) {
        int val = b[i];
        while (val > 1) {
            pf2[minp[val]]++;
            val /= minp[val];
        }
    }

    for (auto &it : pf1) {
        int p = it.x, cnt1 = it.y;
        if (pf2.count(p)) {
            int cnt2 = pf2[p];
            del1[p] = min(cnt1, cnt2);
            del2[p] = min(cnt1, cnt2);
        }
    }

    for (int i = 1; i <= n; i++) {
        int val = a[i];
        while (val > 1) {
            int p = minp[val];
            if (del1[p] > 0) {
                del1[p]--;
                a[i] /= p;
            }
            val /= p;
        }
    }
    for (int i = 1; i <= m; i++) {
        int val = b[i];
        while (val > 1) {
            int p = minp[val];
            if (del2[p] > 0) {
                del2[p]--;
                b[i] /= p;
            }
            val /= p;
        }
    }

    cout << n << " " << m << "\n";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= m; i++) {
        cout << b[i] << " ";
    }
}   
