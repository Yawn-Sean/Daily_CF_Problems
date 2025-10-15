LL get_bit_length(LL x) {
    LL res = 0;
    while (x > 0) {
        x /= 2;
        res++;
    }
    return res;
}

bool check(LL ans, LL period, LL n) {
    LL cnt = get_bit_length(n) / period;
    LL res = 0;
    for (int i = 1; i <= cnt; i++) {
        res = (res << period) + ans;
    }
    return res <= n;
}

LL get_cnt(LL period, LL n) {
    LL l = (1LL << (period - 1)), r = (1LL << period) - 1, mid;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (check(mid, period, n)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (check(r, period, n)) {
        return r - (1LL << (period - 1)) + 1;
    } else if (check(l, period, n)) {
        return l - (1LL << (period - 1)) + 1;
    } 
    return 0;
}

LL calc(LL n) {
    LL maxlen = get_bit_length(n);
    vector<LL> cnt(maxlen + 1, 0);
    for (int target_len = 1; target_len < maxlen; target_len++) {
        for (int period = 1; period < target_len; period++) {
            if (target_len % period == 0) {
                cnt[target_len / period] += (1LL << (period - 1));
            }
        }
    }

    for (int period = 1; period < maxlen; period++) {
        if (maxlen % period == 0) {
            cnt[maxlen / period] += get_cnt(period, n);
        }
    }

    LL res = 0;
    for (int i = maxlen; i > 1; i--) {
        for (int j = 2 * i; j <= maxlen; j += i) {
            cnt[i] -= cnt[j];
        }
        res += cnt[i];
    }
    return res;
} 

void meibao() {
    LL l, r;
    cin >> l >> r;
    // cout << calc(r) << "\n";
    // cout << calc(l - 1) << "\n";
    cout << calc(r) - calc(l - 1) << "\n";
}
