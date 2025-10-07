/*
(a + b) | (a * b)
k * (a + b) = a * b
k * a + k * b = a * b
(k - a) * b + k * a = 0
b = k * a / (a - k)，这说明 k < a
b 需要是最小的，要考察右边的单调性
发现导数 > 0，单调递增的，所以 k 要找最小的
感觉可能要考虑一个根号的算法？但 t = 1e4，根号 1e9 感觉跑不过
那考虑一个 log 的做法？
没说不存在，那就是肯定有了
由于 a + b > a，所以肯定不能是 (a + b) | a，b 在整除中也发挥了作用
或许，会不会 b 本来就不会很大，可以直接枚举出来呢？并不是，暴力算一下 1e9 的发现还挺大的
我们把比较小的情况的 a, b, a + b, a * b 都算一下找找规律
发现 b 有可能比 a 小，也可能比 a 大
发现 gcd(a, b) != 1
还是回到最开始的思路吧，看 (a - k) 什么时候能整除 k * a
a - k < a，所以有可能 (a - k) | a，我们尝试枚举一下 k，再打个表
发现 a - k 不一定整除 a，废了
通过打表我们发现，b 有时候是 a * (a - 1)
总之我们观察到的 gcd(a, b) 一定不是 1
能否直接枚举 a 的某个素因子的倍数？
b 中有 a 的素因子，然后可以把素因子提出来，变成 p * (a + b) / p，这个东西能被 a * b 整除
a * b 里面至少包含 p^2，则 (a + b) 里面至少也要包含 p^2

羊的转化：
(a + b) 能整除 (a + b) * a，所以目标可以变成 (a + b) | a^2
这下变成了 a + b 如何尽快变成 a^2 的一个大于 a 的约数
我们可以对 a 进行素因数分解，组合出其约数，这个数量只有几百个
如何组合？我们可以从小到大枚举素因数，枚举素因数的次数，然后和已经有的约数（初始只有 1）相乘，得到新的约数
然后，我们应该注意到 a^2 的约数是 a 的某两个约数的乘积
所以我们可以枚举约数，找恰好乘起来超过 a 的就好了
*/ 

LL primes[N], cnt;
bool is_prime[N];

void meibao() {
    LL a;
    cin >> a;
    LL root = sqrt(a);
    LL val = a;
    vector<PLL> prime_factors;
    for (int i = 0; i < cnt; i++) {
        LL p = primes[i];
        if (p > root) {
            break;
        }

        if (val % p == 0) {
            LL c = 0;
            while (val % p == 0) {
                val /= p;
                c++;
            }
            prime_factors.push_back({p, c});
        }
    }

    if (val > 1) {
        prime_factors.push_back({val, 1});
    }

    vector<LL> factors;
    factors.push_back(1);
    for (auto it : prime_factors) {
        LL p = it.first;
        for (int i = 1; i <= it.second; i++) {
            vector<LL> new_factors;
            for (int j = 0; j < factors.size(); j++) {
                new_factors.push_back(factors[j] * p);
            }
            for (auto factor : new_factors) {
                factors.push_back(factor);
            }
            p *= it.first;
        }
    }

    sort(factors.begin(), factors.end());

    LL res = INFLL;
    int len = factors.size();
    len--;
    for (int i = 0; i < factors.size(); i++) {
        int j = 0;
        for ( ; j < factors.size(); j++) {
            if (factors[i] * factors[j] > a) {
                break;
            } 
        }
        if (j < factors.size() && factors[i] * factors[j] > a) {
            res = min(res, factors[i] * factors[j] - a);
        }
    }
    cout << res << "\n";
}   
