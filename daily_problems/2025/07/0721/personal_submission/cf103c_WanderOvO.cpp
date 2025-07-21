/*
不妨先打表找规律
找到规律了，发现和 n 的奇偶有关，n 不变时，k 变大，逐渐就是先分割着，然后再插空
*/

bool st[N];
string res;
int max_win_cnt = -1;

void dfs(int u, int cnt, int n, int k) {
    if (u == n) {
        if (cnt == k) {
            int win = 0;
            for (int s = 0; s < n; s++) {
                for (int i = 0; i < n; i++) {
                    if (st[(i + s) % n]) {
                        if (i % 2) {
                            win++;
                        }
                        break;
                    }
                }
            }
            if (win > max_win_cnt) {
                max_win_cnt = win;
                string new_res = "";
                for (int i = 0; i < n; i++) {
                    new_res += (st[i] ? "1" : "0");
                }
                res = new_res;
            } else if (win == max_win_cnt) {
                string new_res = "";
                for (int i = 0; i < n; i++) {
                    new_res += (st[i] ? "1" : "0");
                }
                if (new_res < res) {
                    res = new_res;
                }
            }
        }
        return;
    }

    if (cnt > k) {
        return;
    }

    dfs(u + 1, cnt, n, k);
    st[u] = true;
    dfs(u + 1, cnt + 1, n, k);
    st[u] = false;
}

void calc(LL n, LL k) {
    for (int i = 0; i < n; i++) {
        st[i] = false;
    }
    res = "";
    max_win_cnt = -1;
    dfs(0, 0, n, k);
    cout << res << "\n";
}

void meibao() {
    LL n, k;
    cin >> n >> k;
    LL last_bullet = n, first_bullet = 0, first_continous_bullet = 0;
    if (n % 2) {
        if (k == 0) {
            last_bullet = n + 1;
            first_bullet = n + 1;
            first_continous_bullet = n + 1;
        } else if (k == n) {
            first_bullet = 1;
            first_continous_bullet = 1;
        } else {
            if (k == 1) {
                last_bullet = n;
                first_bullet = n;
                first_continous_bullet = n;
            } else if (k == 2) {
                last_bullet = n;
                first_bullet = n - 1;
                first_continous_bullet = n - 1;
            } else {
                k -= 2;
                if (k <= (n - 2) / 2) {
                    first_bullet = n - 3 - k * 2 + 2;
                    first_continous_bullet = n - 1;
                } else {
                    first_bullet = 2;
                    LL left = k - (n - 2) / 2;
                    first_continous_bullet = n - 2 - left * 2 + 2;
                }
            }
        }
    } else {
        if (k == 0) {
            last_bullet = n + 1;
            first_bullet = n + 1;
            first_continous_bullet = n + 1;
        } else if (k == n) {
            first_bullet = 1;
            first_continous_bullet = 1;
        } else {
            if (k <= n / 2) {
                first_continous_bullet = last_bullet;
                first_bullet = n - k * 2 + 2;
            } else {
                first_bullet = 2;
                LL left = k - n / 2;
                first_continous_bullet = n - 1 - left * 2 + 2;
            }
        }
    }

    int p;
    cin >> p;
    while (p--) {
        LL pos;
        cin >> pos;
        if (last_bullet == n + 1) {
            cout << ".";
        } else {
            if (pos >= first_continous_bullet) {
                cout << "X";
            } else if (pos >= first_bullet) {
                if (pos % 2 == first_bullet % 2) {
                    cout << "X";
                } else {
                    cout << ".";
                }
            } else {
                cout << ".";
            }
        }
    }
}
