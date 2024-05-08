// https://codeforces.com/contest/1114/submission/258084000
void sol() {
    LL n, b;
    cin >> n >> b;
    vector<LL> Prime, Pow1, Pow2;
    for (LL i = 2; i <= b / i; i++) {
        if (b % i == 0) {
            LL p = 0;
            while (b % i == 0) {
                p++;
                b /= i;
            }
            Pow1.push_back(p);
            Prime.push_back(i);
        }
    }
    if (b > 1) {
        Prime.push_back(b);
        Pow1.push_back(1);
    }
    Pow2.resize(Pow1.size());
    for (LL i = 0; i < Prime.size(); i++) {
        LL t = n;
        while (t) {
            Pow2[i] += t / Prime[i];
            t /= Prime[i];
        }
    }
    LL res = LNF;
    for (int i = 0; i < Prime.size(); i++) {
        res = min(res, Pow2[i] / Pow1[i]);
    }
    cout << res << '\n';
}
