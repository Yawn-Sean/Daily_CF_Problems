int n;
string s;

int get(char c) {
    if (isdigit(c)) return c - '0';
    if (c >= 'a' and c <= 'z') return 10 + c - 'a';
    return 36 + c - 'A';
}

char getc(int x) {
    if (x < 10) return '0' + x;
    if (x < 36) return x - 10 + 'a';
    return x - 36 + 'A';
}

void solve() {
    cin >> n;
    vector<int> cnt(62);
    cin >> s;
    for (auto c : s) {
        cnt[get(c)] += 1;
    }
    int one = 0;
    for (int i = 0; i < 62; i ++) {
        one += (cnt[i] & 1);
    }
    
    auto check = [&](int len, int t) -> bool {
        if (len % 2 == 0 and one > 0) return false;
        if (len % 2 == 0) return true;
        return t >= one;
    };
    
    auto out = [&](int len, int t) -> void {
        vector<string> res(t);
        vector<string> mid(t);
        int j1 = 0, j2 = 0;
        for (int i = 0; i < 62; i ++) {
            if (cnt[i] % 2 == 1) {
                mid[j2 ++].push_back(getc(i));
                cnt[i] -= 1;
            }
            while (j1 < t and cnt[i] > 0) {
                res[j1].push_back(getc(i));
                cnt[i] -= 2;
                if (sz(res[j1]) == len / 2) j1 ++;
            }
            while (j1 == t and j2 < t and cnt[i] > 0) {
                mid[j2 ++].push_back(getc(i));
                cnt[i] -= 1;
            }
        }
        for (int i = 0; i < t; i ++) {
            cout << res[i] << mid[i];
            reverse(all(res[i]));
            cout << res[i] << ' ';
        }
        cout << endl;
    };
    
    vector<int> v{n};
    for (int i = 2; i <= n / i; i ++) {
        if (n % i == 0) {
            v.push_back(i);
            if (n / i != i) {
                v.push_back(n / i);
            }
        }
    }
    sort(all(v), greater<int>());
    
    for (auto x : v) {
        if (check(x, n / x)) {
            cout << n / x << endl;
            out(x, n / x);
            return;
        }
    }
    cout << n << endl;
    for (auto c : s) {
        cout << c << ' ';
    }
    cout << endl;
}