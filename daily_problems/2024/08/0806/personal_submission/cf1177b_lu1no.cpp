ULL cnt[100], sum[100], st[100];
int n = 17;

void init() {
    LL p = 1;
    for (int i = 1; i <= n; i++) {
        st[i] = p;
        cnt[i] = 1ULL * 9 * p * i;
        p *= 10;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = cnt[i];
        sum[i] += sum[i - 1];
    }
}

void solve() {
    ULL k;
    cin >> k;
    ULL w = 0;
    for (int i = 1; i <= n; i++) {
        if (sum[i] >= k) {
            k -= sum[i - 1];
            w = i;
            break;
        }
    }
    // cout << k << ' ' << w << endl;
    ULL now = st[w] + k / w + (k % w != 0) - 1;
    string s = to_string(now);
    s = ' ' + s;
    if (k % w == 0)
        cout << s[w] << endl;
    else
        cout << s[k % w] << endl;
}
