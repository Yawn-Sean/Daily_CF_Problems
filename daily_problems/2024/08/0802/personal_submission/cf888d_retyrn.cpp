int n, k;
int P[5] = {0, 1, 2, 9, 44};

ll C(int a, int b) {
    ll res = 1;
    for (int i = a; i > a - b; i --) {
        res *= i;
    }
    for (int i = 1; i <= b; i ++) {
        res /= i;
    }
    return res;
}

void solve() {
    // 至多k个不一样
    cin >> n >> k;
    ll res = 1; // 0
    for (int i = 2; i <= k; i ++) {
        res += C(n, i) * P[i - 1];
    }
    cout << res << endl;
}