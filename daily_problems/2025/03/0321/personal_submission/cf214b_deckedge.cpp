
void solve() {
    bool found = false;
    int n = read(), sum = 0, mod;
    ve<int> cnt(10, 0);
    rep(i, 0, n) {
        int x = read();
        cnt[x]++;
        sum += x;
        if (!x) {
            found = true;
        }
    }
    if (!found) {
        cout << -1 << '\n';
        return ;
    }
    if (!sum) {
        cout << 0 << '\n';
        return ;
    }
    mod = sum % 3;
    if (mod) {
        if (mod == 1) {
            found = false;
            for (int i = 1; i <= 9; i += 3) {
                if (cnt[i] > 0) {
                    cnt[i]--;
                    sum -= i;
                    found = true;
                    break;
                }
            }
            if (!found) {
                int mut = 2;
                for (int i = 2; i < 10 && mut; i += 3) {
                    while (cnt[i] > 0 && mut) {
                        cnt[i]--;
                        sum -= i;
                        mut--;
                    }
                }
                if (mut) {
                    cout << -1 << '\n';
                    return ;
                } 
            }
        } else {
            found = false;
            for (int i = 2; i < 10; i += 3) {
                if (cnt[i]) {
                    cnt[i]--;
                    sum -= i;
                    found = true;
                    break;
                }
            }
            if (!found) {
                int mut = 2;
                for (int i = 1; i < 10 && mut; i += 3) {
                    while (cnt[i] && mut) {
                        cnt[i]--;
                        sum -= i;
                        mut--;
                    }
                }
                if (mut) {
                    cout << -1 << '\n';
                    return ;
                }
            }
        }
    }
    string res;
    per(i, 9, 1) {
        res += string(cnt[i], '0' + i);
    }
    res += string(cnt[0], '0');
    if (res.empty()) {
        cout << 0 << '\n';
        return ;
    }
    found = true;
    for (char c : res) {
        if (c != '0') {
            found = false;
            break;
        }
    }
    if (!found) {
        cout << res << '\n';
    } else {
        cout << 0 << '\n';
    }
}
