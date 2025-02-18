/*
枚举从第 i 位开始，s1 字典序严格大于 s2
*/

LL n, m;
LL a[N], b[N], zero_cnt[N];

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    LL larger_cnt = 0;
    LL tot_cnt = 1;
    int mod = MOD1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            tot_cnt *= m;
            tot_cnt %= mod;
        }
        if (b[i] == 0) {
            tot_cnt *= m;
            tot_cnt %= mod;
        }
        zero_cnt[i] = zero_cnt[i - 1];
        zero_cnt[i] += (a[i] == 0);
        zero_cnt[i] += (b[i] == 0);
    }
    bool finished = false;
    LL pre_same = 1;
    for (int i = 1; i <= n && !finished; i++) {
        if (a[i] == 0 && b[i] == 0) {
            LL c = m * (m - 1) / 2;
            c %= mod;
            c *= pre_same;
            c %= mod;
            c *= qpow(m, zero_cnt[n] - zero_cnt[i], mod);
            c %= mod;
            larger_cnt += c;
            larger_cnt %= mod;
            pre_same *= m;
            pre_same %= mod;
        } else if (a[i] == 0) {
            LL c = m - b[i];
            c *= qpow(m, zero_cnt[n] - zero_cnt[i], mod);
            c %= mod;
            c *= pre_same;
            c %= mod;
            larger_cnt += c;
            larger_cnt %= mod;
        } else if (b[i] == 0) {
            LL c = a[i] - 1;
            c *= qpow(m, zero_cnt[n] - zero_cnt[i], mod);
            c %= mod;
            c *= pre_same;
            c %= mod;
            larger_cnt += c;
            larger_cnt %= mod;
        } else {
            if (a[i] < b[i]) {
                finished = true;
            } else if (a[i] > b[i]) {
                LL c = pre_same;
                c *= qpow(m, zero_cnt[n] - zero_cnt[i], mod);
                c %= mod;
                larger_cnt += c;
                larger_cnt %= mod;
                finished = true;
            } 
        }
    }
    cout << larger_cnt * qpow(tot_cnt, mod - 2, mod) % mod << "\n";
}    
