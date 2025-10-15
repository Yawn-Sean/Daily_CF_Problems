/*
我是先手，想赢的话需要 gcd > 1
倘若因数有奇数个，则最后 1 肯定跑先拿的人手里了，先拿的人必输
倘若因数有偶数个，我第一个显然拿 n 最好，因为 n 包含了所有的因数，最全
以下只讨论有偶数个因数的情况怎么拿：
为了让 gcd > 1，我应该选定 n 中某个素因子，之后选的数都得是包含这个素因子的
n 有很多素因子，到底选谁呢？选在因数中出现次数最多的？
假设 n 只有一种素因子，则 n = p^k，假设有偶数个因数的话先拿是必胜的
n 不止有一种素因子，则 n = p^k1 * q*k2
如果是 n = pq，则奇数必败，所以 k1 和 k2 至少有一个 > 1
如果第一个人上来选了 n，第二个人选带 p 的
之后第一个人需要抉择最后是要 p 还是 q
我们注意到总有这样几个数：1 p q p^2 或 1 p q q^2
第一个人肯定是想拿 q 和 q^2 或 p 和 p^2，但只要它拿了某一个，另一个肯定会被我们拿走，所以后手也是必胜的
*/ 

LL n;

void meibao() {
    cin >> n;
    LL root = sqrt(n);
    vector<LL> factors;
    for (int i = 1; i <= root; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) {
                factors.push_back(n / i);
            }
        }
    }

    if (factors.size() % 2) {
        cout << "N\n";
    } else {
        vector<PII> p;
        for (int i = 2; i <= root; i++) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    cnt++;
                    n /= i;
                }
                p.push_back({i, cnt});
            }
        }
        if (n > 1) {
            p.push_back({n, 1});
        }

        if (p.size() == 1) {
            if (p[0].second % 2 == 0) {
                cout << "N\n";
            } else {
                cout << "Y\n";
            }
        } else {
            if (p.size() == 2 && p[0].second == 1 && p[1].second == 1) {
                cout << "Y\n";
            } else {
                cout << "N\n";
            }
        }
    }
}   
